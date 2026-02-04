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
extern  double range[];
extern size_t i;
extern  size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    size_t i;
    for (i = 0; i <= n; i += 2) {
        h->range[i] = range[i];
        if (i + 1 <= n) {
            h->range[i + 1] = range[i + 1];
        }
    }
}
