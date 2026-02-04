#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int min_bits;
extern int max_bits;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc((max_bits + 10) * sizeof(int));
    if (!array) return;
    for (bits = min_bits + 1; bits <= max_bits; ++bits) {
        array[bits * 3] = bits; // Strided access with stride of 3
    }
    free(array);
}
