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
    int src_offset = (ix * incX) * 2;
    int dst_offset = (iy * incY) * 2;
    ((double *)Y)[dst_offset] = ((const double *)X)[src_offset];
    ((double *)Y)[dst_offset + 1] = ((const double *)X)[src_offset + 1];
    ix++;
    iy++;
}
}
