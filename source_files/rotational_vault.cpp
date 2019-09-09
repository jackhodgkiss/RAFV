#include "../header_files/rotational_vault.hpp"

#include <iostream>

/**
 * Construct a fuzzy vault with the supplied arguments. 
 */
RotationalVault::RotationalVault(unsigned short vault_size, unsigned short vault_width, unsigned short vault_height, 
        Polynomial vault_polynomial, const std::shared_ptr<std::mt19937>& mersenne_twister_engine) 
        : FuzzyVault(vault_size, vault_width, vault_height, vault_polynomial, mersenne_twister_engine), 
        quad_tree(this->vault_width, this->vault_height, 3, this->vault_data)
{
}

std::vector<Coordinate> RotationalVault::lock_vault(const std::vector<unsigned short>& locking_elements)
{
    return FuzzyVault::lock_vault(locking_elements);
}

Polynomial RotationalVault::unlock_vault(std::vector<Coordinate> vault_data, const std::vector<unsigned short>& unlocking_elements)
{
    return FuzzyVault::unlock_vault(vault_data, unlocking_elements);
}