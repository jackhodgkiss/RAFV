#include <memory>
#include <random>
#include <iostream>
#include <algorithm>
#include "../header_files/polynomial.hpp"
#include "../header_files/fuzzy_vault.hpp"
#include "../header_files/rotational_vault.hpp"

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

std::vector<std::pair<int, bool>> generate_rotation_pattern(int pattern_length, int quadrant_count, std::shared_ptr<std::mt19937> mersenne_twister)
{
    std::vector<std::pair<int, bool>> result;
    auto quadrant_distribution = std::uniform_int_distribution<unsigned short>(0, quadrant_count);
    auto direction_distribution = std::uniform_int_distribution<unsigned short>(0, 2);
    for(auto counter = 0; counter < pattern_length; counter++)
    {
        auto pair = std::pair<int, bool>(quadrant_distribution(*mersenne_twister), 
            (direction_distribution(*mersenne_twister) == 0 ? true : false));
        result.push_back(pair);
    }
    return result;
}

int main(int argc, char** argv) 
{
    auto mersenne_twister = get_mersenne_twister();
    auto polynomial = Polynomial(7, mersenne_twister);
    auto rotational_vault = RotationalVault(5000, 8192, 8192, polynomial, mersenne_twister);
    auto rotation_pattern = generate_rotation_pattern(32, 84, mersenne_twister);
    auto vault = rotational_vault.lock_vault({6973, 3439, 3406, 2050, 7210, 7495, 7783, 4476}, rotation_pattern);
}