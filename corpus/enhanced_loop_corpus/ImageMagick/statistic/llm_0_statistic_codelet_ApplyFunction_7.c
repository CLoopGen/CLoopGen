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
    for (i = 0; i < (ssize_t)number_parameters; i++) {
        double temp = ((double)1. / (double)((Quantum)65535.)) * (double)pixel;
        for (ssize_t j = 0; j < 1; j++) {
            result = result * temp + parameters[i];
        }
    }
}
