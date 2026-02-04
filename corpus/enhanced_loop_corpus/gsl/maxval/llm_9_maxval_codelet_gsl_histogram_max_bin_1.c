#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern  gsl_histogram *h;
extern size_t i;
extern size_t imax;
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max = -__builtin_huge_val();
    imax = 0;

    for (i = 0; i < h->n && i < 64; i++) {
        double val = h->bin[i];
        int cmp = (val > max);
        max = cmp * val + (1 - cmp) * max;
        imax = cmp * i + (1 - cmp) * imax;
    }
}
