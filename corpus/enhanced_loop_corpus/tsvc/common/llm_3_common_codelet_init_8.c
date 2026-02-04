#include <stdio.h>

#include <inttypes.h>

__attribute__((aligned(64))) extern int indx[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to scramble write order
    int indices[32000];
    for (int i = 0; i < 32000; i++) {
        indices[i] = (i * 7) % 32000;  // Generate pseudo-randomized access pattern
    }
    for (int i = 0; i < 32000; i++) {
        int pos = indices[i];
        indx[pos] = (i + 1) % 4 + 1;
    }
}
