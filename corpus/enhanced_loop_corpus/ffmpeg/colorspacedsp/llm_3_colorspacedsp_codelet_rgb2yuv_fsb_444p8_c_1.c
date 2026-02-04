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
    // Variant 2: Indirect Memory Access Pattern via Index Array
    // Use an index array to access elements in a shuffled order, simulating indirect memory access
    int *indices = (int*)malloc(w * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (x = 0; x < w; x++) {
        indices[x] = x;
    }
    // Simple shuffle using deterministic pseudo-random pattern based on rnd
    for (x = 0; x < w; x++) {
        int j = (rnd + x * 7) % w;
        int temp = indices[x];
        indices[x] = indices[j];
        indices[j] = temp;
    }
    // Indirect access using shuffled indices
    for (x = 0; x < w; x++) {
        int idx = indices[x];
        rnd_scratch[1][0][idx] = rnd;
        rnd_scratch[1][1][idx] = rnd;
        rnd_scratch[2][0][idx] = rnd;
        rnd_scratch[2][1][idx] = rnd;
    }
    free(indices);
}
