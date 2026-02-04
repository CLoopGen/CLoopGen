#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nblock;
extern Int32 ftab[257];
extern Int32 i;
extern UChar *eclass8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping array (simulated via modulo-based permutation)
    // Simulate indirect access pattern: access elements in permuted order using a virtual index
    for (i = 0; i < nblock; i++) {
        Int32 idx = (i * 71) % nblock; // Pseudo-random stride-like index, ensures full coverage when nblock is prime
        ftab[eclass8[idx]]++;
    }
}
