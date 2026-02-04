#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t Kevents;
extern  double *ProbArray;
extern size_t k;
extern double *E;
extern double pTotal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes elements at even indices first, then odd indices in a second pass
    size_t stride = 2;
    for (k = 0; k < Kevents; k += stride) {
        E[k] = ProbArray[k] / pTotal;
    }
    for (k = 1; k < Kevents; k += stride) {
        E[k] = ProbArray[k] / pTotal;
    }
}
