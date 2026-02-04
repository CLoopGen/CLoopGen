#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int N;
extern int i;
extern float res;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        for (int k = 0; k < 1; k++) {
            res += ((X[i]) >= 0 ? (X[i]) : (-(X[i])));
        }
    }
}
