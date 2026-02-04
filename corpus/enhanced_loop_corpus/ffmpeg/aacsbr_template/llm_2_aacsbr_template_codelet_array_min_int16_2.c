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
    for (i = 2; i < nel; i += 2)
        min = ((array[i]) > (min) ? (min) : (array[i]));
    // Handle odd-sized arrays by checking the last element if needed
    if (nel % 2 == 1 && nel > 1)
        min = ((array[nel - 1]) > (min) ? (min) : (array[nel - 1]));
}
