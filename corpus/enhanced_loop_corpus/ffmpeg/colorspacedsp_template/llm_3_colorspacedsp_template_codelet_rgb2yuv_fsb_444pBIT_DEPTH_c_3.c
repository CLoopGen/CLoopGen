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
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int *indices = (int*)malloc(w * sizeof(int));
    if (!indices) return; // Graceful failure on alloc error

    // Initialize index map (reversing order for distinct access pattern)
    for (int i = 0; i < w; i++) {
        indices[i] = w - 1 - i;
    }

    for (x = 0; x < w; x++) {
        int idx = indices[x]; // Indirect access via reversed index
        rnd_scratch[1][0][idx] = rnd_scratch[1][1][idx] = 
        rnd_scratch[2][0][idx] = rnd_scratch[2][1][idx] = rnd;
    }

    free(indices);
}
