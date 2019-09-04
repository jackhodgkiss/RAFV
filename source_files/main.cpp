#include <iostream>

#include "../header_files/polynomial.hpp"

int main(int argc, char** argv) 
{
    auto polynomial = Polynomial();
    for(auto coefficient : polynomial.get_coefficients())
    {
        std::cout << coefficient << std::endl;
    }
}
