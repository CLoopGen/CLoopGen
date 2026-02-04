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
    // Variant 1: Strided memory access (step by 2)
    for (x = 0; x < arraysize; x += 2) {
        if (c_array[x] > max_v)
            max_v = c_array[x];
    }
    // Handle odd-sized arrays by checking the last element if missed
    if (arraysize % 2 == 1 && c_array[arraysize - 1] > max_v)
        max_v = c_array[arraysize - 1];
}
