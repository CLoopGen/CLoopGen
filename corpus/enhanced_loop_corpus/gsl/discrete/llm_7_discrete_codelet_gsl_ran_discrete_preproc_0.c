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
    double temp_sum = 0.0;
    for (k = 0; k < Kevents; ++k) {
        temp_sum += ProbArray[k];
        E[k] = temp_sum / pTotal;
    }
}
