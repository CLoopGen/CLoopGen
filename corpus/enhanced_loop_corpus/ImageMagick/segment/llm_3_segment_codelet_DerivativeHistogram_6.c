#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *derivative;
extern ssize_t i;
extern ssize_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with offset read pattern (shifted access window)
    for (i = 1; i < n - 2; i++)
        derivative[i + 1] = (histogram[i + 2] - histogram[i]) / 2.;
}
