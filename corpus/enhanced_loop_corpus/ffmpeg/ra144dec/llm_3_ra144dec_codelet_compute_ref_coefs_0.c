#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern  LPC_TYPE *autoc;
extern int max_order;
extern int i;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Simulates irregular access pattern via an index array (emulated statically)
    int indices[32];
    for (int j = 0; j < max_order; j++) {
        indices[j] = j; // Identity mapping for generality; could be permuted
    }
    for (int i = 0; i < max_order; i++) {
        int idx = indices[i]; // Indirect access through index array
        gen0[idx] = gen1[idx] = autoc[idx + 1];
    }
}
