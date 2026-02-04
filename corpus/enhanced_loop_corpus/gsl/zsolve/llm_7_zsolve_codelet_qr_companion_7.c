#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *h;
extern size_t nc;
extern size_t i;
extern size_t m;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_index;
    double accumulator = 0.0;
    for (i = m + 2; i <= n; i++) {
        temp_index = (i - 1) * nc + (i - 3);
        accumulator += ((h)[temp_index]);
        ((h)[(i - 1) * nc + (i - 2)]) = accumulator;
    }
}
