#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i_outer;
for (i_outer = 0; i_outer < 1; i_outer++) {
    for (i = 0; i < N; i++) {
        Y[iy] = 0.;
        iy += incY;
    }
}
}
