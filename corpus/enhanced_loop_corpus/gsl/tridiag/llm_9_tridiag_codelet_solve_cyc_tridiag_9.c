#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern double *delta;
extern double *z;
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < N - 1; i++) {
        sum += delta[i-1] * z[i] + delta[i] * z[i-1];
    }
}
