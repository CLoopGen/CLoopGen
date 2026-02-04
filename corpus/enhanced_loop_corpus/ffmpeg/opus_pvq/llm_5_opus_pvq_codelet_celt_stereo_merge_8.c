#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern int N;
extern int i;
extern float xp;
extern float side;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        if (X[i] != 0.0f || Y[i] != 0.0f) {
            xp += X[i] * Y[i];
            side += Y[i] * Y[i];
        }
    }
}
