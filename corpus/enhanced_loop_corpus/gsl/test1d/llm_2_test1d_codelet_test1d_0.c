#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *hr;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (i = 0; i <= 10; i += 2) {
        hr->range[i] = 0.;
    }
    for (i = 1; i <= 10; i += 2) {
        hr->range[i] = 0.;
    }
}
