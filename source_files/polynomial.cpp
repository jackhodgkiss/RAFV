#include "../header_files/polynomial.hpp"

#include <random>

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

unsigned long long Polynomial::evaluate(long indeterminate) { }

std::vector<unsigned short> Polynomial::get_coefficients() { return this->coefficients; }

std::string Polynomial::get_coefficients_as_bit_string() { }

std::string Polynomial::get_coefficients_as_hash() { }

std::string Polynomial::to_string() { }