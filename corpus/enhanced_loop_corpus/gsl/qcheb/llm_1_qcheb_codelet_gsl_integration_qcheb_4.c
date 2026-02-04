#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *cheb24;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 24; i++) {
        for (size_t inner = 0; inner < 1; inner++) {
            cheb24[i] *= 1. / 12.;
        }
    }
}
