#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern double *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < N; j++)
        for (size_t k = 0; k < tda; k++)
            data[j * tda + k] = 12345. + (j * tda + k);
}
