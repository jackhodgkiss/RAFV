#ifndef QUADRANT_H
#define QUADRANT_H

#include <vector>

class Quadrant
{
public:
    Quadrant(unsigned short abscissa, unsigned short ordinate, unsigned short width, 
        unsigned short height, unsigned short level, unsigned short max_level, std::vector<Coordinate>& vault_data);
};

#endif