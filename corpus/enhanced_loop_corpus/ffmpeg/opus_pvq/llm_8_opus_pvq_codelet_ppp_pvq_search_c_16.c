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
    int i;
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            res += ((X[i]) >= 0 ? (X[i]) : (-(X[i])));
            res += ((X[i+1]) >= 0 ? (X[i+1]) : (-(X[i+1])));
        } else {
            res += ((X[i]) >= 0 ? (X[i]) : (-(X[i])));
        }
    }
}
