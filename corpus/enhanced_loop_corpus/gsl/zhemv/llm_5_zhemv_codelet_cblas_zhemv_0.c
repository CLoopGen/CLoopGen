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
for (i = 0; i < N; i++) {
    if (iy % 2 == 0) {
        (((double *)Y)[2 * (iy)]) = 0.;
        (((double *)Y)[2 * (iy) + 1]) = 0.;
    } else {
        (((double *)Y)[2 * (iy)]) = 1.;
        (((double *)Y)[2 * (iy) + 1]) = 1.;
    }
    iy += incY;
}
}
