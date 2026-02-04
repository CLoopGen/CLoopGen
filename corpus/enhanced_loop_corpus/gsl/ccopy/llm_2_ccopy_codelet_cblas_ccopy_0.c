#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *y_ptr = (float *)Y;
    const float *x_ptr = (const float *)X;
    for (i = 0; i < N; i++) {
        y_ptr[0] = x_ptr[0];
        y_ptr[1] = x_ptr[1];
        x_ptr += 2 * incX;
        y_ptr += 2 * incY;
    }
}
