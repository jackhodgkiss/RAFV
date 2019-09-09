#include <memory>
#include <random>
#include <iostream>
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

int main(int argc, char** argv) 
{
    auto mersenne_twister = get_mersenne_twister();
    auto polynomial = Polynomial(7, mersenne_twister);
    auto rotational_vault = RotationalVault(5000, 8192, 8192, polynomial, mersenne_twister);
    auto vault = rotational_vault.lock_vault({6973, 3439, 3406, 2050, 7210, 7495, 7783, 4476});
    auto unlocked_polynomial = rotational_vault.unlock_vault(vault, {302, 4049, 403, 2002});
    for(auto coordinate : vault)
    {
        std::cout << coordinate.abscissa << ", " << coordinate.ordinate << std::endl;
    }
}