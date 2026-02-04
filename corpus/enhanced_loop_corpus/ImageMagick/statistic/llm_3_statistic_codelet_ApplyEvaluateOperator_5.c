#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double value;
extern double result;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const ssize_t stride = 2;
    double *buffer = (double*)calloc((ssize_t)value * stride, sizeof(double));
    buffer[0] = result;
    for (i = 0; i < (ssize_t)value * stride; i += stride) {
        buffer[i] = (i == 0) ? result : buffer[i - stride] / 2.0;
    }
    result = buffer[(ssize_t)(value - 1) * stride];
    free(buffer);
}
