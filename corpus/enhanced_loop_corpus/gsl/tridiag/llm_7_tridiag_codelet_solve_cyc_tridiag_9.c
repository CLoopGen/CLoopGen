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
    if (N < 3) return;
    double prev = delta[0] * z[0];
    sum = prev;
    for (i = 1; i < N - 2; i++) {
        double curr = delta[i] * z[i];
        sum += curr;
        prev = curr;
    }
}
