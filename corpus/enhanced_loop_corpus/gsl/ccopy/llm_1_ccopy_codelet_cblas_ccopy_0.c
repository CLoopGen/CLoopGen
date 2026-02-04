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
for (i = 0; i < N; i += 2) {
    for (int j = 0; j < 2 && (i + j) < N; j++) {
        int local_i = i + j;
        int local_ix = ix + j * incX;
        int local_iy = iy + j * incY;
        (((float *)Y)[2 * local_iy]) = (((const float *)X)[2 * local_ix]);
        (((float *)Y)[2 * local_iy + 1]) = (((const float *)X)[2 * local_ix + 1]);
    }
    ix += 2 * incX;
    iy += 2 * incY;
}
}
