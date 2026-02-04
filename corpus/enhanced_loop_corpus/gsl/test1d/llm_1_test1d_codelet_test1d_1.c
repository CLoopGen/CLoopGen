#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 198; i++) {
        h1->range[i] = 100. + i;
        h1->range[397 - i] = 100. + (397 - i);
    }
    if (397 % 2 == 0) {
        h1->range[199] = 100. + 199;
    }
}
