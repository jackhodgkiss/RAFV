#ifndef ROTATIONAL_VAULT_H
#define ROTATIONAL_VAULT_H

#include "fuzzy_vault.hpp"

class RotationalVault : public FuzzyVault
{
public:
    RotationalVault(unsigned short vault_size, unsigned short vault_width, unsigned short vault_height, 
        Polynomial vault_polynomial, const std::shared_ptr<std::mt19937>& mersenne_twister_engine = nullptr);
};

#endif