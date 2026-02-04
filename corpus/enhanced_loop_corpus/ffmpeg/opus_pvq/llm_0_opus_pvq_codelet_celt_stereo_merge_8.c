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
    int j;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < N; i++) {
            xp += X[i] * Y[i];
            side += Y[i] * Y[i];
        }
    }
}
