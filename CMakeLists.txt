cmake_minimum_required(VERSION 3.0.0)
project(rotational_assisted_fuzzy_vault VERSION 0.1.0)

set(HEADER_FILES)
set(SOURCE_FILES "source_files/main.cpp")
add_executable(rotational_assisted_fuzzy_vault ${HEADER_FILES} ${SOURCE_FILES})
set_target_properties(rotational_assisted_fuzzy_vault PROPERTIES CXX_STANDARD 17)