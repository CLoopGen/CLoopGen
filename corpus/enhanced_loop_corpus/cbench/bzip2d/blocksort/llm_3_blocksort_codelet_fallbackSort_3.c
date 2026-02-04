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
    // Variant 2: Indirect memory access using a fixed offset table (simulated)
    // Use a small local index map to indirectly determine which eclass8 element to access
    int indices[] = {0, 2, 1, 3}; // Example permutation pattern
    int idx_size = 4;
    for (i = 0; i < nblock; i++) {
        int mapped_i = (i % idx_size); // Cycle through the index map
        ftab[eclass8[indices[mapped_i] + (i - i % idx_size)]]++;
    }
}
