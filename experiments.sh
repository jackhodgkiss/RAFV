#!/bin/bash

for vault_size in 100 1000 2000 3000 4000 5000; do
    for max_layer in 3 4; do
        for rotation_count in 16 32 64 128 256; do
            results_output="results/${vault_size}_points/${max_layer}_${rotation_count}.csv"
            build/rotational_assisted_fuzzy_vault $vault_size $max_layer $rotation_count > $results_output
        done
    done
done