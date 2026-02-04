#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *max_hdr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i < n_basic_blocks; i += 2)
        max_hdr[i] = -1;
    // Handle odd-sized arrays by ensuring last element is set if needed
    if (n_basic_blocks % 2 == 1) {
        max_hdr[n_basic_blocks - 1] = -1;
    }
}
