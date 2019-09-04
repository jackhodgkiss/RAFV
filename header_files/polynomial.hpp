#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <string>
#include <vector>

/**
 * Polynomial class is responsible for representing a univariate polynomial for use with the fuzzy vault
 * scheme. The fuzzy vault allows for the concealment of a message or key that have been encoded within
 * the polyomial as its coefficients.
 * 
 * NOTE: Whilst the constructor allows for an order to be provided it is only intended to be used 
 *  with an order of 7.
 * NOTE: The coefficients are generated randomly however it is not intended that a cryptographically
 *  secure random number generator will be used in this implementation.
 * NOTE: Polynomial evaluation suffers from integer overflow this may be fixed later. 
 */
class Polynomial
{
    unsigned short order;
    std::vector<unsigned short> coefficients;
public:
    Polynomial(unsigned short order = 7);
    unsigned long long evaluate(long indeterminate = 1);
    std::vector<unsigned short> get_coefficients();
    std::string get_coefficients_as_bit_string();
    std::string get_coefficients_as_hash();
    std::string to_string();
};

#endif