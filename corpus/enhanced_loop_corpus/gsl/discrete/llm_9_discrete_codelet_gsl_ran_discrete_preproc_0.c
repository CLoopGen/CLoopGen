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
    size_t step = 2;
    for (k = 0; k < Kevents - (Kevents % step); k += step) {
        E[k]     = ProbArray[k] / pTotal;
        E[k + 1] = ProbArray[k + 1] / pTotal;
    }
    if (k < Kevents) {
        E[k] = ProbArray[k] / pTotal;
    }
}
