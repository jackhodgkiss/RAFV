#ifndef QUAD_TREE_H
#define QUAD_TREE_H

#include <vector>
#include "quadrant.hpp"
#include "fuzzy_vault.hpp"

class QuadTree
{
    std::vector<std::shared_ptr<Quadrant>> tree_map;
    std::shared_ptr<Quadrant> root;
    std::vector<Coordinate>& vault_data;
    unsigned short width;
    unsigned short height;
    unsigned short max_level;
public:
    QuadTree(unsigned short width, unsigned short height, 
        unsigned short max_level, std::vector<Coordinate>& vault_data);
};

#endif