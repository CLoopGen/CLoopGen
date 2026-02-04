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
    double *y_ptr = (double *)Y;
    const double *x_ptr = (const double *)X;
    int temp_offset_x, temp_offset_y;
    for (i = 0; i < N; i++) {
        temp_offset_x = 2 * (ix + i * incX);
        temp_offset_y = 2 * (iy + i * incY);
        y_ptr[temp_offset_y] = x_ptr[temp_offset_x];
        y_ptr[temp_offset_y + 1] = x_ptr[temp_offset_x + 1];
    }
}
