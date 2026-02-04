#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int i;
extern int *pdom;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with stride-like pattern)
    int *indices = (int*)__builtin_alloca(n_basic_blocks * sizeof(int));
    for (i = 0; i < n_basic_blocks; ++i)
        indices[i] = i;  // Identity mapping, could be randomized or reordered in practice
    for (i = 0; i < n_basic_blocks; ++i)
        pdom[indices[i]] = (-3);
}
