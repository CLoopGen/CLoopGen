#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        Y[i] = X[i];
        if (i + 1 < N)
            Y[i + 1] = X[i + 1];
    }
}
