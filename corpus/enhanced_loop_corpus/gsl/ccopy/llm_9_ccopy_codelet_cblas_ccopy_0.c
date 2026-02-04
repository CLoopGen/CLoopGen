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
for (i = 0; i < N * 3; i++) {
    int local_ix = ix + (i % incX);
    int local_iy = iy + (i % incY);
    float val1 = ((const float *)X)[2 * local_ix];
    float val2 = ((const float *)X)[2 * local_ix + 1];
    ((float *)Y)[2 * local_iy] = val1;
    ((float *)Y)[2 * local_iy + 1] = val2;
}
}
