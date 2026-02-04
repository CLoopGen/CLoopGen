#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointer and using stride of 2
    float *y_ptr = (float *)Y;
    int idx = 2 * iy;
    for (i = 0; i < lenY; i++) {
        y_ptr[idx]     = 0.0f;
        y_ptr[idx + 1] = 0.0f;
        idx += 2 * incY;
    }
}
