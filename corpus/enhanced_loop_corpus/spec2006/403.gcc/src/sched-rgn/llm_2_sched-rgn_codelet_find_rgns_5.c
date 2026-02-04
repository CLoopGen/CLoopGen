#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *degree;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    // Initialize only even indices first, then odd if within bounds
    int i;
    for (i = 0; i < n_basic_blocks; i += 2)
        degree[i] = 0;
    for (i = 1; i < n_basic_blocks; i += 2)
        degree[i] = 0;
}
