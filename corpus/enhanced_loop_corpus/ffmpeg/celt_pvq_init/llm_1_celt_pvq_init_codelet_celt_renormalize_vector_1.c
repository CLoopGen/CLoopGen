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
        i = 0;
        for (; i < N; ) {
            g += X[i] * X[i];
            i++;
        }
    }
}
