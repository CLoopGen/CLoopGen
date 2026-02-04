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
    for (i = 2; i <= nmax; i++) {
        res[i] *= local_f;
        local_f *= i;
    }
    f = local_f;
}
