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
for (size_t i = 0; i < Kevents; i += 2) {
    size_t end = (i + 1 < Kevents) ? i + 2 : i + 1;
    for (size_t k = i; k < end; ++k) {
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
