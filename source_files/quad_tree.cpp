#include "../header_files/quad_tree.hpp"

#include <iostream>

QuadTree::QuadTree(unsigned short width, unsigned short height, 
    unsigned short max_level, std::vector<Coordinate>& vault_data) 
    : width(width), height(height), max_level(max_level), vault_data(vault_data)
{
    this->root = std::make_shared<Quadrant>(0, 0, this->width, this->height, 
        0, this->max_level, this->vault_data, this->tree_map);
    this->tree_map.push_back(root);
    this->tree_map.at(0)->get_occupants();
    this->tree_map.at(32)->get_occupants();
    this->tree_map.at(16)->get_occupants();   
    this->tree_map.at(84)->get_occupants();
}