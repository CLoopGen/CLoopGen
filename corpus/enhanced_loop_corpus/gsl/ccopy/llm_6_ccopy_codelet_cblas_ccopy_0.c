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
    int j;
    for (i = 0; i < N; i++) {
        j = ix; // Introduce temporary to modify data dependency (WAW and RAW partially broken)
        (((float *)Y)[2 * (iy)]) = (((const float *)X)[2 * (j)]);
        (((float *)Y)[2 * (iy) + 1]) = (((const float *)X)[2 * (j) + 1]);
        ix += incX;
        iy += incY;
    }
}
