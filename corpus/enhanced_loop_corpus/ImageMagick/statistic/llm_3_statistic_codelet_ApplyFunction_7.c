#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern Quantum pixel;
extern  size_t number_parameters;
extern  double *parameters;
extern double result;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access – traverse array from last to first
    ssize_t n = (ssize_t)number_parameters;

    for (i = n - 1; i >= 0; i--) {
        result = result * ((double)1. / (double)((Quantum)65535.)) * (double)pixel + parameters[i];
    }
}
