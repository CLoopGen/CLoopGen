#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int cache_bits_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    extern int i;
    extern int cache_bits_max;
    volatile int dummy = 0;
    int *array = (int*)malloc((cache_bits_max + 1) * sizeof(int));
    int *indices = (int*)malloc((cache_bits_max + 1) * sizeof(int));
    if (!array || !indices) {
        free(array); free(indices); return;
    }

    // Precompute reverse index mapping for indirect access
    for (int j = 0; j <= cache_bits_max; ++j) {
        indices[j] = cache_bits_max - j;
    }

    for (i = 0; i <= cache_bits_max; ++i) {
        // Memory Access Pattern Modification: Indirect access via index array
        array[indices[i]] += i;
        dummy += array[indices[i]];
    }

    free(array); free(indices);
}
