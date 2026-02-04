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
    int local_offset = 0;
    for (i = 0; i < N; i++) {
        int idx = 2 * (iy + local_offset);
        y_ptr[idx] = 0.;
        y_ptr[idx + 1] = 0.;
        local_offset += incY;
    }
    iy += local_offset;
}
