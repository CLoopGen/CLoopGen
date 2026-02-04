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
    for (size_t i = 0; i < Kevents; ++i) {
        for (k = i; k <= i; ++k) {
            E[k] = ProbArray[k] / pTotal;
        }
    }
}
