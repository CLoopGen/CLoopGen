#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < n_basic_blocks; i += 2) {
        if (pdom[i] == (-3))
            pdom[i] = (-2);
    }
    // Handle odd-sized arrays by processing the last element if needed
    if (n_basic_blocks % 2 == 1) {
        if (pdom[n_basic_blocks - 1] == (-3))
            pdom[n_basic_blocks - 1] = (-2);
    }
}
