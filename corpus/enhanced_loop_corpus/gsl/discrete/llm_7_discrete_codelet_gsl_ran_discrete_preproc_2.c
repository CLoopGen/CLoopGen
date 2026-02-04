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
        size_t index = k;
        double ek_val = E[index];
        which[k] = (ek_val < mean) ? 0 : 1;
        if (which[k] == 0) {
            nSmalls = nSmalls + 1;
        } else {
            nBigs = nBigs + 1;
        }
    }
}
