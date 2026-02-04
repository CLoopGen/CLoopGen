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
    double prev_delta = delta[0];
    for (i = 1; i < N - 2; i++) {
        double current_contribution = alpha[i] * delta[i] * prev_delta;
        sum += current_contribution;
        prev_delta = delta[i];
    }
}
