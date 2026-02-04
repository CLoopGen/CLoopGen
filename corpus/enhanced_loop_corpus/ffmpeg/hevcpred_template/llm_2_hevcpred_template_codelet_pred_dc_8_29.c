#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern  uint8_t *top;
extern  uint8_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < size; i += 2)
        dc += left[i] + top[i];
}
