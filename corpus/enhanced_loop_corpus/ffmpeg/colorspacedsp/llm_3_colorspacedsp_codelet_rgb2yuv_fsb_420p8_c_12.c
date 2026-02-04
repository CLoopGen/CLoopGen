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
    // Variant 2: Indirect memory access using an index map (simulated via simple permutation)
    int *indices = (int*)malloc(w * sizeof(int));
    if (!indices) return;
    
    // Create a simple indirect access pattern: reverse order
    for (int i = 0; i < w; i++) {
        indices[i] = w - 1 - i;
    }

    for (x = 0; x < w; x++) {
        int idx = indices[x];
        rnd_scratch[0][0][idx] = rnd;
        rnd_scratch[0][1][idx] = rnd;
    }

    free(indices);
}
