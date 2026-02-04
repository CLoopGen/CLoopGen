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
    for (i = 2; i < n - 1; i += 2) {
        derivative[i] = (histogram[i + 1] - histogram[i - 1]) / 2.0;
        derivative[i + 1] = (histogram[i + 2] - histogram[i]) / 2.0;
    }
    if (i == n - 1) {
        derivative[i] = (histogram[i + 1] - histogram[i - 1]) / 2.0;
    }
}
