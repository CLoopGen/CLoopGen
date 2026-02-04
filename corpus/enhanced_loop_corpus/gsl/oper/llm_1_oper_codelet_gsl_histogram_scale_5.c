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
extern double scale;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h->n > 0) {
        i = 0;
        for (size_t step = 1; step <= h->n; step++) {
            h->bin[i] *= scale;
            i++;
        }
    }
}
