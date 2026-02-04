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
if (N > 0) {
    int i_inner;
    for (i_inner = 0; i_inner < N; i_inner++) {
        i = i_inner;
        (((double *)Y)[2 * (iy)]) = 0.;
        (((double *)Y)[2 * (iy) + 1]) = 0.;
        iy += incY;
    }
} else {
    i = 0;
}
}
