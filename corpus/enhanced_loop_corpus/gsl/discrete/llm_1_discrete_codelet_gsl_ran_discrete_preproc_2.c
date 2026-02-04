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
if (Kevents > 0) {
    for (k = 0; k < Kevents; ++k) {
        for (size_t inner = 0; inner < 1; ++inner) {
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
}
