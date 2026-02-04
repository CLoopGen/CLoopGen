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
    if (number_parameters > 0) {
        for (i = 0; i < (ssize_t)number_parameters; i += 2) {
            result = result * ((double)1. / (double)((Quantum)65535.)) * (double)pixel + parameters[i];
            if (i + 1 < (ssize_t)number_parameters) {
                result = result * ((double)1. / (double)((Quantum)65535.)) * (double)pixel + parameters[i + 1];
            }
        }
    }
}
