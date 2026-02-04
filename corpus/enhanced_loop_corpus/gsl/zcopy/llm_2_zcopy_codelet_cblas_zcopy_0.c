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
for (i = 0; i < N; i++) {
    int src_idx = ix * 2;
    int dst_idx = iy * 2;
    ((double *)Y)[dst_idx] = ((const double *)X)[src_idx];
    ((double *)Y)[dst_idx + 1] = ((const double *)X)[src_idx + 1];
    ix += incX;
    iy += incY;
}
}
