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
    // Variant 2: Reverse consecutive memory access
    // Iterates from the last element to the first
    for (k = Kevents; k > 0; --k) {
        size_t idx = k - 1;
        E[idx] = ProbArray[idx] / pTotal;
    }
}
