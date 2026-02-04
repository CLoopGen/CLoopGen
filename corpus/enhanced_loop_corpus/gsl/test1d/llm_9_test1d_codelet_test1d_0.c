#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *hr;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 10; i++) {
        hr->range[i] = 0.;
        hr->bin[i] = (hr->range[i + 1] - hr->range[i]) * 0.5;
    }
}
