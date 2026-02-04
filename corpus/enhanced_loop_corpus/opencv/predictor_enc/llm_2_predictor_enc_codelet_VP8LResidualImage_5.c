#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int min_bits;
extern int max_bits;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc((max_bits - min_bits + 1) * sizeof(int));
    if (!array) return;
    for (bits = min_bits + 1; bits <= max_bits; ++bits) {
        array[bits - min_bits - 1] = bits * 2; // Consecutive write access
    }
    free(array);
}
