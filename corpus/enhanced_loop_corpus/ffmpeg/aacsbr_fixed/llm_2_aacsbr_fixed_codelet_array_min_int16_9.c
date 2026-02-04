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
    // Handle the last element if nel is even and i skipped it
    if (nel % 2 == 0 && nel - 1 > 0)
        min = ((array[nel - 1]) > (min) ? (min) : (array[nel - 1]));
}
