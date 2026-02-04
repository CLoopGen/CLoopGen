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
    size_t indices[398];
    for (i = 0; i <= 397; i++) {
        indices[i] = 397 - i; // reverse access pattern
    }
    for (i = 0; i <= 397; i++) {
        size_t idx = indices[i];
        h1->range[idx] = 100. + idx;
    }
}
