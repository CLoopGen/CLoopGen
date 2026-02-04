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
    int outer_i;
    int step = 1;
    for (outer_i = 0; outer_i < N; outer_i += step) {
        i = outer_i;
        g += X[i] * X[i];
    }
}
