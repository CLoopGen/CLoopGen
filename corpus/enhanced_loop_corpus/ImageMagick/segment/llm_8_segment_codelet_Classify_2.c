#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern double *squares;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = -255; i <= 255; i += 2) {
        double val = (double)i;
        squares[i] = val * val;
    }
}
