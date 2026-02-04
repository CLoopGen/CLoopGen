#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element forward and backward)
    int stride = 2;
    for (i = 0; i < 10; i += stride) {
        if (i < 10) weight[i] <<= shift;
    }
    for (i = 1; i < 10; i += stride) {
        if (i < 10) weight[i] <<= shift;
    }
}
