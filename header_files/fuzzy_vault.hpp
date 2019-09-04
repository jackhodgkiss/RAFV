#ifndef FUZZY_VAULT_H
#define FUZZY_VAULT_H

#include <random>
#include <memory>
#include <vector>
#include "../header_files/polynomial.hpp"

/**
 * Represent an abscissa, ordinate (X, Y) that represents a single point within 2D space.
 */
struct Coordinate
{
    unsigned short abscissa, ordinate;
    Coordinate(unsigned short abscissa, unsigned short ordinate) 
    { 
        this->abscissa = abscissa, this->ordinate = ordinate;
    }
};

/**
 * Construct a fuzzy vault according the fuzzy vault scheme published by Ari Juels and Madhu Sudan. 
 * 
 * NOTE: Not a complete implemention of the scheme.
 */
class FuzzyVault
{
    std::vector<Coordinate> vault_data;
    unsigned short vault_size;
    unsigned short vault_width, vault_height;
    Polynomial vault_polynomial;
    std::shared_ptr<std::mt19937> mersenne_twister_engine;
    void project_elements(const std::vector<unsigned short>& locking_elements);
    void apply_chaff();
    void order_vault();
public:
    FuzzyVault(unsigned short vault_size, unsigned short vault_width, unsigned short vault_height, 
        Polynomial vault_polynomial, const std::shared_ptr<std::mt19937>& mersenne_twister_engine = nullptr);
    std::vector<Coordinate> lock_vault(const std::vector<unsigned short>& locking_elements);
    static Polynomial unlock_vault(std::vector<Coordinate> vault_data, const std::vector<unsigned short>& unlocking_elements);
};

#endif