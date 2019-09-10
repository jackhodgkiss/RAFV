#include "../header_files/quad_tree.hpp"

#include <iostream>

QuadTree::QuadTree(unsigned short width, unsigned short height, 
    unsigned short max_level, std::vector<Coordinate>& vault_data) 
    : width(width), height(height), max_level(max_level), vault_data(vault_data), 
    root(0, 0, width, height, 0, max_level, vault_data, tree_map)
{
    this->tree_map.push_back(std::make_shared<Quadrant>(root));
    for(auto quadrant : this->tree_map)
    {
        std::cout << std::addressof(*quadrant.get()) << std::endl;
    }
}