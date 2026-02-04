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
    for (i = 0; i < N; i++) {
        int idx = 2 * iy;
        y_ptr[idx] = 0.0f;
        y_ptr[idx + 1] = 0.0f;
        iy += incY;
    }
}
