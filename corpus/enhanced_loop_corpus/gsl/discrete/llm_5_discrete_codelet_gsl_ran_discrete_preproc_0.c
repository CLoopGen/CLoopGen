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
    double inv_pTotal = (pTotal != 0.0) ? 1.0 / pTotal : 0.0;
    for (k = 0; k < Kevents; ++k) {
        if (ProbArray[k] > 0.0) {
            E[k] = ProbArray[k] * inv_pTotal;
        } else {
            E[k] = 0.0;
        }
    }
}
