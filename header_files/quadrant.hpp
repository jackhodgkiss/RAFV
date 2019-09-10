#ifndef QUADRANT_H
#define QUADRANT_H

#include <vector>
#include <memory>
#include "coordinate.hpp"

class Quadrant
{
    std::shared_ptr<Quadrant> north_east = nullptr;
    std::shared_ptr<Quadrant> south_east = nullptr;
    std::shared_ptr<Quadrant> south_west = nullptr;
    std::shared_ptr<Quadrant> north_west = nullptr;
    std::vector<Coordinate>& vault_data;
    std::vector<std::shared_ptr<Quadrant>>& tree_map;
    void divide();
public:
    Quadrant(unsigned short abscissa, unsigned short ordinate, unsigned short width, 
        unsigned short height, unsigned short level, unsigned short max_level, std::vector<Coordinate>& vault_data, 
        std::vector<std::shared_ptr<Quadrant>>& tree_map);
    unsigned short abscissa;
    unsigned short ordinate;
    unsigned short width;
    unsigned short height;
    Coordinate center;
    unsigned short level;
    unsigned short max_level;
    std::vector<int> get_occupants();
    std::string to_string();
};

#endif