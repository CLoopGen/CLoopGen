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
    for (i = 0; i < N * 2; i += 2) {
        int offset_x = 2 * (ix);
        int offset_y = 2 * (iy);
        ((double *)Y)[offset_y] = ((const double *)X)[offset_x];
        ((double *)Y)[offset_y + 1] = ((const double *)X)[offset_x + 1];
        if (i + 1 < N) {
            ix += incX;
            iy += incY;
        }
    }
}
