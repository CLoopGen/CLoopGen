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
    for (i = 0; i < N - 2; i += 2) {
        sum += alpha[i] * delta[i] * delta[i];
        if (i + 1 < N - 2) {
            sum += alpha[i + 1] * delta[i + 1] * delta[i + 1];
        }
    }
}
