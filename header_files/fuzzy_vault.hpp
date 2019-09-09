#ifndef FUZZY_VAULT_H
#define FUZZY_VAULT_H

#include <random>
#include <memory>
#include <vector>
#include "polynomial.hpp"
#include "coordinate.hpp"

/**
 * Construct a fuzzy vault according the fuzzy vault scheme published by Ari Juels and Madhu Sudan. 
 * 
 * NOTE: Not a complete implemention of the scheme.
 */
class FuzzyVault
{
    unsigned short vault_size;
    Polynomial vault_polynomial;
    std::shared_ptr<std::mt19937> mersenne_twister_engine;
protected:
    std::vector<Coordinate> vault_data;
    unsigned short vault_width, vault_height;
    void project_elements(const std::vector<unsigned short>& locking_elements);
    void apply_chaff();
    void order_vault();
public:
    FuzzyVault();
    FuzzyVault(unsigned short vault_size, unsigned short vault_width, unsigned short vault_height, 
        Polynomial vault_polynomial, const std::shared_ptr<std::mt19937>& mersenne_twister_engine = nullptr);
    std::vector<Coordinate> lock_vault(const std::vector<unsigned short>& locking_elements);
    Polynomial unlock_vault(std::vector<Coordinate> vault_data, const std::vector<unsigned short>& unlocking_elements);
};

#endif