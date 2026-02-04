#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *array;
extern int nel;
extern int i;
extern int min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int unroll_factor = 4;
    int remainder = nel % unroll_factor;
    for (i = 1; i < remainder; i++) {
        min = (array[i] < min) ? array[i] : min;
    }
    for (; i < nel; i += unroll_factor) {
        min = (array[i] < min) ? array[i] : min;
        if (i + 1 < nel) min = (array[i + 1] < min) ? array[i + 1] : min;
        if (i + 2 < nel) min = (array[i + 2] < min) ? array[i + 2] : min;
        if (i + 3 < nel) min = (array[i + 3] < min) ? array[i + 3] : min;
    }
}
