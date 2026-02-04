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
    double local_accumulator = (double)pixel * ((double)1. / (double)((Quantum)65535.));
    double temp = result;
    for (i = 0; i < (ssize_t)number_parameters; i++) {
        double input = parameters[i];
        temp = temp * local_accumulator + input;
    }
    result = temp;
}
