#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index array (simulated via computed indices)
    int indices[16];
    for (int i = 0; i < 16; i++) {
        indices[i] = (i * i) % 32; // Non-linear index pattern
    }
    for (in = 0; in < ((255 + 1) / 16); in++, out++) {
        int idx = indices[in % 16];
        table[idx] = out;
        table[-idx] = -out;
    }
}
