#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated via arithmetic)
    int indices[256];
    for (i = 0; i <= 255; i++)
        indices[i] = (i * 3 + 1) % 256;  // Simple pseudo-random permutation
    for (i = 0; i <= 255; i++) {
        int idx = indices[i];
        table[idx] = (JSAMPLE)idx;
    }
}
