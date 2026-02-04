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
    if (Kevents > 0) {
        k = 0;
        for (size_t outer = 0; outer < 1; ++outer) {
            for (; k < Kevents; ++k) {
                E[k] = ProbArray[k] / pTotal;
            }
        }
    }
}
