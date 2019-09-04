#include <memory>
#include <random>
#include <iostream>
#include "../header_files/polynomial.hpp"

/**
 * Generate a mersenne twister that has been seeded using a sequence 32 integers. The mersenne twister 
 * has been placed within a shared_ptr for use by other objects as a resource. 
 */
std::shared_ptr<std::mt19937> get_mersenne_twister()
{
    std::seed_seq seed_sequence{13273, 11528, 9692, 9902, 8065, 5185, 11423, 14042,
                                5114, 13245, 9996, 5942, 7750, 10119, 8489, 13262,
                                10154, 7609, 12548, 12387, 9283, 4175, 5364, 10668,
                                10477, 12330, 10251, 10233, 9560, 10203, 11761, 10168};
    return std::make_shared<std::mt19937>(seed_sequence);
}

int main(int argc, char** argv) 
{
    auto mersenne_twister = get_mersenne_twister();
    std::uniform_int_distribution<int> uniform_distribution(0, 8192);
    for(auto i = 0; i <= 500; i++)
    {
        std::cout << uniform_distribution(*mersenne_twister) << std::endl;
    }
}
