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
    if (N > 0) {
        int i = 0;
        for (; i < N - 1; i += 2) {
            g += X[i] * X[i] + X[i+1] * X[i+1];
        }
        if (i < N) {
            g += X[i] * X[i];
        }
    }
}
