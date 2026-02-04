#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h;
extern gsl_histogram *h1;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    size_t limit = 398;
    for (i = 0; i < limit; i += 2) {
        if (h1->range[i] != h->range[i])
            status = 1;
        if ((i + 1) < limit && h1->range[i + 1] != h->range[i + 1])
            status = 1;
    }
}
