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
    int j;
    for (i = 0; i < N; i++) {
        j = iy + incY;
        (((double *)Y)[2 * (iy)]) = 0.;
        (((double *)Y)[2 * (j)]) = 0.;
        iy += incY;
    }
}
