#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < n_basic_blocks; i += 2)
        pdom[i] = (-3);
    // Handle odd-sized arrays by ensuring all elements are covered if needed
    for (i = 1; i < n_basic_blocks; i += 2)
        pdom[i] = (-3);
}
