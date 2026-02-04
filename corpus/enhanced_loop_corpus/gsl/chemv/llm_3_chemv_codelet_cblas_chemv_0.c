#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *y_ptr = (float *)Y;
    int base_offset = 2 * iy;
    int stride = 2 * incY;
    for (i = 0; i < N; i++) {
        y_ptr[base_offset] = 0.0f;
        y_ptr[base_offset + 1] = 0.0f;
        base_offset += stride;
    }
}
