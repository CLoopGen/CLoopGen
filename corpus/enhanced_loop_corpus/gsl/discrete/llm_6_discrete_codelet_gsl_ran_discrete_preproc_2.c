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
    size_t temp_nSmalls = 0;
    size_t temp_nBigs = 0;
    for (k = 0; k < Kevents; ++k) {
        if (E[k] < mean) {
            temp_nSmalls++;
            which[k] = 0;
        } else {
            temp_nBigs++;
            which[k] = 1;
        }
    }
    nSmalls += temp_nSmalls;
    nBigs += temp_nBigs;
}
