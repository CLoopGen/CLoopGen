#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern size_t j;
extern double *data;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        for (j = N + 1; j < tda; j += 2) {
            double val1 = data[i * tda + j];
            double val2 = data[i * tda + j - 1];
            double ref1 = 12345. + (i * tda + j);
            double ref2 = 12345. + (i * tda + j - 1);
            status |= ((val1 != ref1) | (val2 != ref2));
        }
    }
}
