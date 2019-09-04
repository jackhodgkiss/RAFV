#include "../header_files/fuzzy_vault.hpp"

#include <iostream>
#include <algorithm>

FuzzyVault::FuzzyVault(unsigned short vault_size, unsigned short vault_width, unsigned short vault_height, 
        Polynomial vault_polynomial, const std::shared_ptr<std::mt19937>& mersenne_twister_engine)
{
    this->vault_size = vault_size;
    this->vault_width, this->vault_height = vault_width, vault_height;
    this->vault_polynomial = vault_polynomial;
    this->mersenne_twister_engine = mersenne_twister_engine;
}

std::vector<Coordinate> FuzzyVault::lock_vault(const std::vector<unsigned short>& locking_elements)
{
    this->project_elements(locking_elements);
    this->apply_chaff();
    this->order_vault();
    return this->vault_data;
}

void FuzzyVault::project_elements(const std::vector<unsigned short>& locking_elements)
{
    for(auto abscissa : locking_elements)
    {
        unsigned short ordinate = this->vault_polynomial(abscissa) % this->vault_height;
        this->vault_data.push_back(Coordinate(abscissa, ordinate));
    }
}

void FuzzyVault::apply_chaff()
{
    std::vector<unsigned short> reserved_abscissas, permitted_abscissas, selected_abscissas;
    for(auto coordinate : this->vault_data) { reserved_abscissas.push_back(coordinate.abscissa); }
    auto distribution = std::uniform_int_distribution<unsigned short>(0, this->vault_width);
    auto generate_permitted_abscissas = [n = 0, &reserved_abscissas] () mutable
    {
        n++;
        auto find_result = std::find(reserved_abscissas.begin(), reserved_abscissas.end(), n);
        return find_result != std::end(reserved_abscissas) ? 0 : n;
    };
    std::generate(permitted_abscissas.begin(), permitted_abscissas.end(), generate_permitted_abscissas);
    selected_abscissas = {23, 69, 7045, 303};
    for(auto abscissa : selected_abscissas)
    {
        unsigned short invalid_ordinate = this->vault_polynomial(abscissa) % this->vault_height;
        bool has_found_ordinate = false; unsigned long ordinate = 0;
        while(!has_found_ordinate)
        {
            ordinate = distribution(*this->mersenne_twister_engine);
            has_found_ordinate = (ordinate != 0 && ordinate != invalid_ordinate) ? true : false;
        }
        this->vault_data.push_back(Coordinate(abscissa, ordinate));
    }
}

void FuzzyVault::order_vault() { }