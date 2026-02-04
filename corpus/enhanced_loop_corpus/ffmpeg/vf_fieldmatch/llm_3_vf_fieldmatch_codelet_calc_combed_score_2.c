#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int max_v;
extern int *c_array;
extern  int arraysize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with stride-like pattern as index array)
    int *indices = (int*)malloc(arraysize * sizeof(int));
    for (int i = 0; i < arraysize; i++)
        indices[i] = i;  // Identity mapping for generality (could be randomized or reordered in real use)

    for (x = 0; x < arraysize; x++) {
        int idx = indices[x];  // Indirect access via index array
        if (c_array[idx] > max_v)
            max_v = c_array[idx];
    }

    free(indices);
}
