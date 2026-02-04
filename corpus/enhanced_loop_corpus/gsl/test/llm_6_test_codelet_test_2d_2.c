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
    size_t idx;
    double base = 12345.0;
    for (i = 0; i < N * tda; i++) {
        idx = i;
        data[idx] = base + idx;
    }
}
