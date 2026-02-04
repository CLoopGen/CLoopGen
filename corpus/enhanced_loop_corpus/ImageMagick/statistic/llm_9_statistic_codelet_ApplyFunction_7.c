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
    result = 0.0;
    for (i = 0; i < (ssize_t)(number_parameters / 2); i++) {
        double temp1 = (double)pixel * (1.0 / 65535.0);
        double temp2 = temp1 * 0.5;
        result += temp1 * parameters[i] + temp2;
    }
    if (number_parameters > 0) {
        result += (double)pixel / 65535.0;
    }
}
