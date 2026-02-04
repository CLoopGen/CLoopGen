#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dims_count;
extern  float *src;
extern float *dst;
extern  float *src1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Iterates from the last element to the first, maintaining unit stride but reversing order
    for (int i = dims_count - 1; i >= 0; --i) {
        dst[i] = src[i] / src1[i];
    }
}
