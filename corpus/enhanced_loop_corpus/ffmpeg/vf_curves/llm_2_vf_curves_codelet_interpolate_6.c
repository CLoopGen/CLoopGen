#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *y;
extern int i;
extern  int lut_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < lut_size; i += 2) {
        if (i < lut_size) y[i] = i;
    }
    // Fill remaining element if lut_size is odd
    if (lut_size % 2 == 1) {
        y[lut_size - 1] = lut_size - 1;
    }
}
