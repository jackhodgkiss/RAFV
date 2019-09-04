#include <iostream>

#include "../header_files/polynomial.hpp"

int main(int argc, char** argv) 
{
    auto polynomial = Polynomial();
    std::cout << "P(X) = " << polynomial.to_string() << std::endl;
    std::cout << "P(5) = " << polynomial.evaluate(5) << std::endl;
    std::cout << "P(10) = " << polynomial(10) << std::endl;
    std::cout << "Bit string: " << polynomial.get_coefficients_as_bit_string() << std::endl;
    std::cout << "SHA256: " << polynomial.get_coefficients_as_hash() << std::endl;
}
