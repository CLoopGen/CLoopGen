#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int *rnd_scratch[3][2];
extern int x;
extern  int rnd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an auxiliary index array to access memory locations indirectly.
    // Simulates irregular or data-dependent access patterns.
    // Since we cannot introduce new global state, we allocate a local VLA (Variable Length Array) for indices.
    if (w <= 0) return;
    int *indices = alloca(w * sizeof(int));
    for (int i = 0; i < w; i++) {
        indices[i] = i;  // Identity mapping for determinism, but pattern allows reordering
    }
    for (x = 0; x < w; x++) {
        int idx = indices[x];  // Indirect access through index array
        rnd_scratch[0][0][idx] = rnd_scratch[0][1][idx] = rnd;
    }
}
