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
    size_t stride = 2;
    for (k = 0; k < Kevents; k += stride) {
        if (k + 1 < Kevents) {
            // Process two elements per iteration to increase computational intensity
            if (E[k] < mean) {
                ++nSmalls;
                which[k] = 0;
            } else {
                ++nBigs;
                which[k] = 1;
            }
            if (E[k + 1] < mean) {
                ++nSmalls;
                which[k + 1] = 0;
            } else {
                ++nBigs;
                which[k + 1] = 1;
            }
        } else {
            // Handle last element if Kevents is odd
            if (E[k] < mean) {
                ++nSmalls;
                which[k] = 0;
            } else {
                ++nBigs;
                which[k] = 1;
            }
        }
    }
}
