#ifndef QUAD_TREE_H
#define QUAD_TREE_H

#include <vector>
#include "fuzzy_vault.hpp"

class QuadTree
{
    std::vector<Coordinate>& vault_data;
    unsigned short width;
    unsigned short height;
    unsigned short number_of_layers;
public:
    QuadTree(unsigned short width, unsigned short height, 
        unsigned short number_of_layers, std::vector<Coordinate>& vault_data);
};

#endif