#ifndef ROTATIONAL_VAULT_H
#define ROTATIONAL_VAULT_H

#include "quad_tree.hpp"
#include "coordinate.hpp"
#include "fuzzy_vault.hpp"

class RotationalVault : public FuzzyVault
{
    void rotate_vault(QuadTree quad_tree, std::vector<std::pair<int, bool>> rotation_pattern);
    void rotate_point(int index, bool clockwise_direction, Coordinate center);
public:
    RotationalVault();
    RotationalVault(unsigned short vault_size, unsigned short vault_width, unsigned short vault_height, 
        Polynomial vault_polynomial, const std::shared_ptr<std::mt19937>& mersenne_twister_engine = nullptr);
    virtual std::vector<Coordinate> lock_vault(const std::vector<unsigned short>& locking_elements, 
        int max_layer, std::vector<std::pair<int, bool>> rotation_pattern);
    virtual Polynomial unlock_vault(std::vector<Coordinate> vault_data, 
        const std::vector<unsigned short>& unlocking_elements, std::vector<std::pair<int, bool>> rotation_pattern);
};

#endif
