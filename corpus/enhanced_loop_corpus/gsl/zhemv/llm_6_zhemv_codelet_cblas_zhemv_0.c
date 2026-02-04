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
    int idx = 2 * iy;
    for (i = 0; i < N; i++) {
        y_ptr[idx] = 0.;
        y_ptr[idx + 1] = 0.;
        idx += 2 * incY;
    }
}
