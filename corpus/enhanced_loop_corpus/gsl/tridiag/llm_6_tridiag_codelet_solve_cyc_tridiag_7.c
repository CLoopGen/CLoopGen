#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern double *delta;
extern double *alpha;
extern size_t i;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (i = 0; i < N - 2; i++) {
        temp_sum += alpha[i] * delta[i] * delta[i];
    }
    sum += temp_sum;
}
