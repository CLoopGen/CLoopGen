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
    for (i = 1; i < n; i++) {
        derivative[i] = 0.0;
        if (i % 2 == 0) {
            continue;
        }
        derivative[i] = (histogram[i + 1] - histogram[i - 1]) / 2.;
    }
}
