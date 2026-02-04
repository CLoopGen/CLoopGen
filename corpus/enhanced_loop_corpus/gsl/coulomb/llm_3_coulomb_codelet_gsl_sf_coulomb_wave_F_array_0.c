#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    int *indices = (int*)malloc((kmax + 1) * sizeof(int));
    if (!indices) return; // Handle malloc failure
    int i;
    for (i = 0; i <= kmax; i++) {
        indices[i] = i; // Populate index array (could be shuffled in real use cases)
    }
    for (i = 0; i <= kmax; i++) {
        fc_array[indices[i]] = 0.;
    }
    free(indices);
}
