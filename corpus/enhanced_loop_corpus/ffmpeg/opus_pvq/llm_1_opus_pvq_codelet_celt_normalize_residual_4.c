#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *restrict iy;
extern float *restrict X;
extern int N;
extern float g;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i1;
    for (i1 = 0; i1 < N; i1 += 2) {
        if (i1 < N)
            X[i1] = g * iy[i1];
        if (i1 + 1 < N)
            X[i1 + 1] = g * iy[i1 + 1];
    }
}
