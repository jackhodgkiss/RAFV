cmake_minimum_required(VERSION 3.0.0)
project(rotational_assisted_fuzzy_vault VERSION 0.1.0)

set(HEADER_FILES "header_files/polynomial.hpp" "header_files/picosha2.h")
set(SOURCE_FILES "source_files/main.cpp" "source_files/polynomial.cpp")
add_executable(rotational_assisted_fuzzy_vault ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(rotational_assisted_fuzzy_vault PROPERTIES CXX_STANDARD 17)