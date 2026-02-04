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
    int temp_iy = iy;
    for (i = 0; i < N; i++) {
        int base_idx = 2 * temp_iy;
        y_ptr[base_idx] = 0.;
        y_ptr[base_idx + 1] = y_ptr[base_idx]; // Introduce RAW dependency: use of prior write
        temp_iy += incY;
    }
    iy = temp_iy; // Update outer state only once (eliminates loop-carried WAW on iy)
}
