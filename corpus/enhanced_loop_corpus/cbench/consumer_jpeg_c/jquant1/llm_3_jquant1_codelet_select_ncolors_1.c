#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access pattern using index array (simulated via lookup)
    // Create a small indirect lookup table for iteration order
    int *indices = (int*)__builtin_alloca(nc * sizeof(int));
    for (int j = 0; j < nc; j++) {
        indices[j] = nc - 1 - j; // Reverse order access (indirect addressing)
    }
    for (i = 0; i < nc - 1; i++) {
        int idx = indices[i + 1]; // Use indirect index, skip first zero if needed
        temp *= iroot;
    }
}
