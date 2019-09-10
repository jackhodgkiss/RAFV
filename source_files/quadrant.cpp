#include "../header_files/quadrant.hpp"

#include <sstream>
#include <iostream>
#include <algorithm>

Quadrant::Quadrant(unsigned short abscissa, unsigned short ordinate, unsigned short width, 
        unsigned short height, unsigned short level, unsigned short max_level, std::vector<Coordinate>& vault_data, 
        std::vector<std::shared_ptr<Quadrant>>& tree_map) 
        : abscissa(abscissa), ordinate(ordinate), width(width), height(height), 
        level(level), max_level(max_level), vault_data(vault_data), tree_map(tree_map)
{
    this->divide();
    if(this->south_east != nullptr)
    {
        this->tree_map.push_back(this->south_west);
        this->tree_map.push_back(this->south_east);
        this->tree_map.push_back(this->north_east);
        this->tree_map.push_back(this->north_west);
    }
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
            unsigned short quadrant_abscissa = this->abscissa + column * quadrant_width;
            unsigned short quadrant_ordinate = this->ordinate + row * quadrant_height;
            auto child_quadrant = std::make_shared<Quadrant>(quadrant_abscissa, quadrant_ordinate, quadrant_width, 
                quadrant_height, this->level + 1, this->max_level, this->vault_data, this->tree_map);
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

std::vector<int> Quadrant::get_occupants()
{
    auto result = std::vector<int>();
    auto is_in_boundaries = [&] (Coordinate& coordinate) -> bool
    {
        auto coordinate_abscissa = coordinate.abscissa; auto coordinate_ordinate = coordinate.ordinate;
        if(this->abscissa < coordinate_abscissa && this->abscissa + this->width > coordinate_abscissa 
        && this->ordinate  < coordinate_ordinate && this->ordinate + this->height > coordinate_ordinate)
            return true;
        else
            return false;   
    };
    auto vault_iterator = this->vault_data.begin();
    while(vault_iterator != this->vault_data.end())
    {
        vault_iterator = std::find_if(vault_iterator, this->vault_data.end(), is_in_boundaries);
        if(vault_iterator != this->vault_data.end())
        {
            result.push_back(std::distance(this->vault_data.begin(), vault_iterator));
            vault_iterator++;
        }
    }
    return result;
}

std::string Quadrant::to_string() 
{
    std::stringstream result;
    result << "Abscissa: " << this->abscissa << " Ordinate: " << this->ordinate << "\n";
    result << "Width: " << this->width << " Height: " << this->height << "\n";
    result << "End Abscissa: " << this->abscissa + this->width << " End Ordinate: " << this->ordinate + height << "\n";
    return result.str();
}