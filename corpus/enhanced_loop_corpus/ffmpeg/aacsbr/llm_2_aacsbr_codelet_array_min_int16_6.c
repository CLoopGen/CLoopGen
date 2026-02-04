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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 1; i < nel; i += 2)
        min = ((array[i]) > (min) ? (min) : (array[i]));
    // Handle potential last element if nel is even
    if (nel % 2 == 0 && nel > 1) {
        i = nel - 1;
        min = ((array[i]) > (min) ? (min) : (array[i]));
    }
}
