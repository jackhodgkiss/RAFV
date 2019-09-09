#include "../header_files/quadrant.hpp"

#include <iostream>

Quadrant::Quadrant(unsigned short abscissa, unsigned short ordinate, unsigned short width, 
        unsigned short height, unsigned short level, unsigned short max_level, std::vector<Coordinate>& vault_data) 
        : abscissa(abscissa), ordinate(ordinate), width(width), height(height), 
        level(level), max_level(max_level), vault_data(vault_data)
{
    std::cout << this->level << std::endl;
    this->divide();
}

void Quadrant::divide()
{
    if(this->level < this->max_level)
    {
        unsigned short quadrant_width = this->width / 2;
        unsigned short quadrant_height = this->height / 2;
        for(auto counter = 0; counter < 4; counter++)
        {
            unsigned short row = counter / 2;
            unsigned short column = counter % 2;
            unsigned short quadrant_abscissa = column * quadrant_width;
            unsigned short quadrant_ordinate = row * quadrant_height;
            auto child_quadrant = std::make_shared<Quadrant>(quadrant_abscissa, quadrant_ordinate, quadrant_width, 
                quadrant_height, this->level + 1, this->max_level, this->vault_data);
            if(counter == 0)
                this->south_west = child_quadrant;
            else if(counter == 1)
                this->south_east = child_quadrant;
            else if(counter == 2)
                this->north_west = child_quadrant;
            else
                this->north_east = child_quadrant;
        }
    }
}