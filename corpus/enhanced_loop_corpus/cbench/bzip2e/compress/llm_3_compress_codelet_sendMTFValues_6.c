#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

extern UChar pos[6];
extern Int32 i;
extern Int32 nGroups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Simulates indirect access pattern via a lookup table (could represent permutation or scatter)
    // Here we use a simple identity-based index map for generality and correctness
    Int32 index_map[6];
    for (i = 0; i < nGroups; i++) {
        index_map[i] = i; // Could be arbitrary permutation, but kept as identity for correctness
    }
    for (i = 0; i < nGroups; i++) {
        pos[index_map[i]] = i;
    }
}
