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
    // Variant 2: Reverse consecutive memory access – copy from the end to the beginning
    size_t i;
    for (i = n; i > 0; --i) {
        dest->bin[i - 1] = src->bin[i - 1];
    }
}
