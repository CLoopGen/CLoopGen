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
    double inv_pTotal = 1.0 / pTotal;
    for (k = 0; k < Kevents; ++k) {
        E[k] = ProbArray[k] * inv_pTotal;
    }
}
