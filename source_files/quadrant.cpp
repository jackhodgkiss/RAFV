#include "../header_files/quadrant.hpp"

#include <iostream>

Quadrant::Quadrant(unsigned short abscissa, unsigned short ordinate, unsigned short width, 
        unsigned short height, unsigned short level, unsigned short max_level, std::vector<Coordinate>& vault_data) 
        : abscissa(abscissa), ordinate(ordinate), width(width), height(height), 
        level(level), max_level(max_level), vault_data(vault_data)
{
    std::cout << "Max Level: " <<  max_level << std::endl;
}