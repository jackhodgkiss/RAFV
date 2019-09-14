#include "../header_files/rotational_vault.hpp"

#include <iostream>
#include <algorithm>

/**
 * Construct a fuzzy vault with the supplied arguments. 
 */
RotationalVault::RotationalVault(unsigned short vault_size, unsigned short vault_width, unsigned short vault_height, 
        Polynomial vault_polynomial, const std::shared_ptr<std::mt19937>& mersenne_twister_engine) 
        : FuzzyVault(vault_size, vault_width, vault_height, vault_polynomial, mersenne_twister_engine)
{
}

RotationalVault::RotationalVault()  {}

void RotationalVault::rotate_vault(QuadTree quad_tree, std::vector<std::pair<int, bool>> rotation_pattern)
{
    for(auto pair : rotation_pattern)
    {
        auto point_indices = quad_tree.get_occupants(pair.first);
        auto center = quad_tree.get_center(pair.first);
        for(auto index : point_indices)
        {
            this->rotate_point(index, pair.second, center);
        }
    }
}

void RotationalVault::rotate_point(int index, bool clockwise_direction, Coordinate center)
{
    auto original_abscissa = this->vault_data[index].abscissa;
    auto original_ordinate = this->vault_data[index].ordinate;
    if(clockwise_direction)
    {
        this->vault_data[index].abscissa = original_ordinate - center.ordinate + center.abscissa;
        this->vault_data[index].ordinate = -1 * (original_abscissa - center.abscissa) + center.ordinate;
    }
    else
    {
        this->vault_data[index].abscissa = -1 * (original_ordinate - center.ordinate) + center.abscissa;
        this->vault_data[index].ordinate = 1 * (original_abscissa - center.abscissa) + center.ordinate;
    }
}

std::vector<Coordinate> RotationalVault::lock_vault(const std::vector<unsigned short>& locking_elements,
    int max_layer, std::vector<std::pair<int, bool>> rotation_pattern)
{
    FuzzyVault::lock_vault(locking_elements);
    auto quad_tree = QuadTree(this->vault_width, this->vault_height, max_layer, this->vault_data);
    this->rotate_vault(quad_tree, rotation_pattern);
    return this->vault_data;
}

Polynomial RotationalVault::unlock_vault(std::vector<Coordinate> vault_data, 
    const std::vector<unsigned short>& unlocking_elements, std::vector<std::pair<int, bool>> rotation_pattern)
{
    return FuzzyVault::unlock_vault(vault_data, unlocking_elements);
}
