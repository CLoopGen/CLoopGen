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
    for (i = 0; i < (N - 2) / 2; i++) {
        sum += delta[2*i] * z[2*i];
        if (2*i + 1 < N - 2) {
            sum += delta[2*i + 1] * z[2*i + 1];
        }
    }
    if ((N - 2) % 2 == 1) {
        sum += delta[N - 3] * z[N - 3];
    }
}
