#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double res[];
extern size_t i;
extern size_t nmax;
extern double f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_f = f;
    size_t unroll_factor = 4;
    size_t limit = nmax - (nmax % unroll_factor);
    for (i = 2; i <= limit; i += unroll_factor) {
        local_f *= i;
        res[i] *= local_f;
        local_f *= (i + 1);
        res[i + 1] *= local_f;
        local_f *= (i + 2);
        res[i + 2] *= local_f;
        local_f *= (i + 3);
        res[i + 3] *= local_f;
    }
    for (; i <= nmax; i++) {
        f *= i;
        res[i] *= f;
    }
    f = local_f;
}
