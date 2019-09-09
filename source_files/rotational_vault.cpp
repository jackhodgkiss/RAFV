#include "../header_files/rotational_vault.hpp"

#include <iostream>

/**
 * Construct a fuzzy vault with the supplied arguments. 
 */
RotationalVault::RotationalVault(unsigned short vault_size, unsigned short vault_width, unsigned short vault_height, 
        Polynomial vault_polynomial, const std::shared_ptr<std::mt19937>& mersenne_twister_engine) 
        : FuzzyVault(vault_size, vault_width, vault_height, vault_polynomial, mersenne_twister_engine)
{
    std::cout << "Hello from RotationalVault" << std::endl;
}