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
    double *y_ptr = (double *)Y;
    int local_offset = iy;
    for (i = 0; i < N; i++) {
        y_ptr[2 * local_offset] = 0.;
        y_ptr[2 * local_offset + 1] = 0.;
        local_offset += incY;
    }
    iy = local_offset;
}
