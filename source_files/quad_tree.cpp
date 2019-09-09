#include "../header_files/quad_tree.hpp"

#include <iostream>

QuadTree::QuadTree(unsigned short width, unsigned short height, 
    unsigned short number_of_layers, std::vector<Coordinate>& vault_data) 
    : width(width), height(height), number_of_layers(number_of_layers), vault_data(vault_data) 
{
}