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
if (N > 0) {
    for (i = 0; i < 1; i++) {
        int j = 0;
        for (; j < N; j++) {
            Y[iy] = 0.;
            iy += incY;
        }
    }
}
}
