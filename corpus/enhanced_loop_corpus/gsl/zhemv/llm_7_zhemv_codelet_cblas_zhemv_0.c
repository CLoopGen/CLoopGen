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
        int offset = 2 * temp_iy;
        y_ptr[offset] = 0.;
        y_ptr[offset + 1] = 0.;
        temp_iy += incY;
    }
    iy = temp_iy; // Introduce WAR dependency: write to iy after loop uses original value
}
