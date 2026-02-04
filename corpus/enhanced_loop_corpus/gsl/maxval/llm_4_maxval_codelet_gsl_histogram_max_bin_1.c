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
    for (i = 0; i < h->n; i++) {
        max = (h->bin[i] > max) ? h->bin[i] : max;
        imax = (h->bin[i] > max) ? i : imax;
    }
}
