#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x[9];
extern double norm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulates non-sequential access pattern)
    int idx_map[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    for (norm = x[6], i = 0; i < 9; ++i)
        x[idx_map[i]] /= norm;
}
