#ifndef COORDINATE_H
#define COORDINATE_H

/**
 * Represent an abscissa, ordinate (X, Y) that represents a single point within 2D space.
 */
struct Coordinate
{
    unsigned short abscissa, ordinate;
    Coordinate(unsigned short abscissa, unsigned short ordinate) 
    { 
        this->abscissa = abscissa, this->ordinate = ordinate;
    }
};

#endif