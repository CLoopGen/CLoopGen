#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *dest;
extern  gsl_histogram *src;
extern size_t n;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    size_t i;
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            dest->bin[i]     = src->bin[i];
            dest->bin[i + 1] = src->bin[i + 1];
        } else {
            dest->bin[i] = src->bin[i];
        }
    }
}
