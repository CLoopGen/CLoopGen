#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        Y[iy] = 0.;
        Y[iy] += 1.0f;
        Y[iy] -= 1.0f;
        iy += incY;
    }
}
