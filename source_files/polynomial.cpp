#include "../header_files/polynomial.hpp"

#include <bitset>
#include <random>
#include <sstream>
#include "../header_files/picosha2.h"

/**
 * Construct a univariate polynomial with the desired order. A mersenne twister is to be provided to allow 
 * for determistic polynomial construction.
 */
Polynomial::Polynomial(unsigned short order, const std::shared_ptr<std::mt19937>& mersenne_twister_engine) 
{
    if(mersenne_twister_engine == nullptr) return;
    this->order = order;
    auto distribution = std::uniform_int_distribution<unsigned short>(0, 65535);
    for(auto counter = 0; counter <= this->order; counter++)
    {
        auto coefficient = distribution(*mersenne_twister_engine);
        this->coefficients.push_back(coefficient);
    }
}

/**
 * Evaluate the polynomial with the supplied indeterminate. This uses Horner's method of polynomial evaluation
 * which removes the need for evaluation using exponents. See https://en.wikipedia.org/wiki/Horner%27s_method.
 */
unsigned long long Polynomial::evaluate(long indeterminate) 
{
    unsigned long long result = 0;
    for(auto &coefficient : this->coefficients)
    {
        result = result * indeterminate + coefficient;
    }
    return result;
}

/**
 * See Polynomial::evaluate for implementation details. 
 */
unsigned long long Polynomial::operator()(long indeterminate) { return this->evaluate(indeterminate); }

std::vector<unsigned short> Polynomial::get_coefficients() { return this->coefficients; }

/**
 * Obtain a representation of coefficients as a string of bits. Assumes 7 order polynomial
 * with 16 bits per coefficient making the maximum size of the bit string 128.
 */
std::string Polynomial::get_coefficients_as_bit_string() 
{
    std::bitset<128> result(*this->coefficients.begin());
    for(auto iterator = this->coefficients.begin() + 1; iterator != this->coefficients.end(); iterator++)
    {
        auto coefficient_bits = std::bitset<128>(*iterator);
        result = (result << 16 ^ coefficient_bits);
    }
    return result.to_string();
}

/**
 * Generate a hash of the coefficients that make up the polynomial.
 *
 * NOTE: SHA256 implementation provided by Github user okdshin (https://github.com/okdshin/PicoSHA2)
 */
std::string Polynomial::get_coefficients_as_hash() 
{
    auto coefficients_as_bit_string = this->get_coefficients_as_bit_string();
    return picosha2::hash256_hex_string(coefficients_as_bit_string);
}

std::string Polynomial::to_string() 
{
    std::string result;
    for(auto iterator = this->coefficients.begin(); iterator != this->coefficients.end(); iterator++)
    {
        std::stringstream term;
        std::string coefficient = std::to_string(*iterator);
        auto exponent = this->coefficients.size() - std::distance(this->coefficients.begin(), iterator) - 1;
        if(exponent == 0)
        {
            term << coefficient;
        }
        else if(exponent == 1)
        {
            term << coefficient << " * X + ";
        }
        else
        {
            term << coefficient << " * X^" << exponent << " + ";
        }
        result.append(term.str());
    }
    return result;
}