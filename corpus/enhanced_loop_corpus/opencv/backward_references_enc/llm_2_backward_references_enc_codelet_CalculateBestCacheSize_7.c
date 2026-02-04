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
    if (!array) return;

    for (i = 0; i <= cache_bits_max; ++i) {
        // Memory Access Pattern Modification: Consecutive write access to array
        array[i] = i * 2;
        dummy += array[i];
    }

    free(array);
}
