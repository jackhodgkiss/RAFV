cmake_minimum_required(VERSION 3.0.0)
project(rotational_assisted_fuzzy_vault VERSION 0.1.0)

set(HEADER_FILES "header_files/polynomial.hpp" "header_files/picosha2.h" "header_files/coordinate.hpp" 
    "header_files/fuzzy_vault.hpp" "header_files/rotational_vault.hpp" "header_files/quad_tree.hpp" 
    "header_files/quadrant.hpp")
set(SOURCE_FILES "source_files/main.cpp" "source_files/polynomial.cpp" "source_files/fuzzy_vault.cpp" 
    "source_files/rotational_vault.cpp" "source_files/quad_tree.cpp" "source_files/quadrant.cpp")
add_executable(rotational_assisted_fuzzy_vault ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(rotational_assisted_fuzzy_vault PROPERTIES CXX_STANDARD 17)