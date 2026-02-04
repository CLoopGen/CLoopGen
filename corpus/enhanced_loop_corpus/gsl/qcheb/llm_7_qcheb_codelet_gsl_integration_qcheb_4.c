#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *cheb24;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 23; i++) {
        cheb24[i+1] = cheb24[i] * (1.0 / 12.0);
    }
    if (i == 23) {
        cheb24[23] *= 1.0 / 12.0;
    }
}
