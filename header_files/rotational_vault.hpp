#ifndef ROTATIONAL_VAULT_H
#define ROTATIONAL_VAULT_H

#include "fuzzy_vault.hpp"

class RotationalVault : public FuzzyVault
{
public:
    RotationalVault();
    RotationalVault(unsigned short vault_size, unsigned short vault_width, unsigned short vault_height, 
        Polynomial vault_polynomial, const std::shared_ptr<std::mt19937>& mersenne_twister_engine = nullptr);
    virtual std::vector<Coordinate> lock_vault(const std::vector<unsigned short>& locking_elements);
    virtual Polynomial unlock_vault(std::vector<Coordinate> vault_data, const std::vector<unsigned short>& unlocking_elements);
};

#endif