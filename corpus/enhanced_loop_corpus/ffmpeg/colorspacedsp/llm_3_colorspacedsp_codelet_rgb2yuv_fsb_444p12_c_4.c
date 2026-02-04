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
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    int *indices = (int*)malloc(w * sizeof(int));
    if (!indices) return;
    for (int i = 0; i < w; i++) {
        indices[i] = i; // direct mapping, but allows for arbitrary reordering
    }
    for (x = 0; x < w; x++) {
        int idx = indices[x]; // indirect access via index table
        rnd_scratch[0][0][idx] = rnd;
        rnd_scratch[0][1][idx] = rnd;
    }
    free(indices);
}
