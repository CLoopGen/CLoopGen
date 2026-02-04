#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int N0;
extern int stride;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < stride; i++) {
    int index_base;
    for (j = 0; j < N0; j++) {
        index_base = stride * (2 * j) + i;
        float x0 = X[index_base];
        float x1 = X[index_base + stride];
        X[index_base] = (x0 + x1) * 0.70710678118654757;
        X[index_base + stride] = (x0 - x1) * 0.70710678118654757;
    }
}
}
