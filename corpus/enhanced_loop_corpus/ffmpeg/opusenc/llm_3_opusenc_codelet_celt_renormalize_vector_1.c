#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int N;
extern int i;
extern float g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < N; i += stride) {
        for (int j = 0; j < stride && (i + j) < N; j++) {
            g += X[i + j] * X[i + j];
        }
    }
}
