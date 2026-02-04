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
    int local_iy = iy;
    for (i = 0; i < N; i++) {
        y_ptr[2 * local_iy] = 0.;
        y_ptr[2 * local_iy + 1] = 0.;
        local_iy += incY;
        // Introduce artificial loop-carried dependency via local update
        // WAW-like pattern avoided by using local accumulator
    }
    // Store back only at the end to remove per-iteration global write
    iy = local_iy;
}
