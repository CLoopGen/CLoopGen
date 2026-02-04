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
    max = h->bin[0];
    imax = 0;
    for (i = 1; i < h->n; i++) {
        if (!(h->bin[i] > max)) continue;
        max = h->bin[i];
        imax = i;
    }
}
