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
    double *range_ptr = hr->range;
    for (i = 0; i <= 10; i++) {
        range_ptr[i] = 0.;
        range_ptr[i+1] = range_ptr[i] + 1.0; // Introduces RAW dependency: current iteration uses previous write
    }
}
