#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern double *squares;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_square = 0.0;
    for (i = (-255); i <= 255; i++) {
        double curr_val = (double)i;
        double curr_square = curr_val * curr_val;
        squares[i] = curr_square + prev_square;
        prev_square = curr_square;
    }
}
