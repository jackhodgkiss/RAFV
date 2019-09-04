#include "../header_files/polynomial.hpp"

#include <bitset>
#include <random>
#include <sstream>

Polynomial::Polynomial(unsigned short order) 
{
    this->order = order;
    std::random_device random_device;
    std::mt19937 generator(random_device());
    auto distribution = std::uniform_int_distribution<unsigned short>(0, 65535);
    for(auto counter = 0; counter <= this->order; counter++)
    {
        auto coefficient = distribution(generator);
        this->coefficients.push_back(coefficient);
    }
}

unsigned long long Polynomial::evaluate(long indeterminate) 
{
    unsigned long long result = 0;
    for(auto &coefficient : this->coefficients)
    {
        result = result * indeterminate + coefficient;
    }
    return result;
}

std::vector<unsigned short> Polynomial::get_coefficients() { return this->coefficients; }

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

std::string Polynomial::get_coefficients_as_hash() { return std::string(); }

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