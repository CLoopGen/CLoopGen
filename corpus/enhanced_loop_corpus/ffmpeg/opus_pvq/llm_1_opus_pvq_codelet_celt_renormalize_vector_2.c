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
for (i = 0; i < N; i++) {
    if (i % 2 == 0) {
        X[i] *= g;
    } else {
        X[i] *= g;
    }
}
}
