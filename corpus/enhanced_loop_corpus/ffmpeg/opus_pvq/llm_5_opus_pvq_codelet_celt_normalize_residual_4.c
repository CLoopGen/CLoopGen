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
    for (i = 0; i < N; i++) {
        if (i % 2 == 0)
            X[i] = g * iy[i];
        else
            X[i] = 0.0f;
    }
}
