#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t Kevents;
extern size_t k;
extern size_t nBigs;
extern size_t nSmalls;
extern double *E;
extern double mean;
extern size_t * which;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < Kevents; ++k) {
        const int isBig = (E[k] >= mean);
        nBigs += isBig;
        nSmalls += !isBig;
        which[k] = isBig;
    }
}
