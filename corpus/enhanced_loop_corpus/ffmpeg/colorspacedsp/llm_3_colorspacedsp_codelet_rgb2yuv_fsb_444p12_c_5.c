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
    // Variant 2: Indirect Memory Access using an index map (simulated via pointer arithmetic)
    int *indices = (int*)malloc(w * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Initialize index map (identity map for correctness, but enables indirect pattern)
    for (int i = 0; i < w; i++) {
        indices[i] = i;
    }

    for (x = 0; x < w; x++) {
        int idx = indices[x]; // Indirect access through index array
        rnd_scratch[1][0][idx] = rnd;
        rnd_scratch[1][1][idx] = rnd;
        rnd_scratch[2][0][idx] = rnd;
        rnd_scratch[2][1][idx] = rnd;
    }

    free(indices);
}
