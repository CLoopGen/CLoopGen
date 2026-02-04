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
    size_t stride = 2;
    for (i = 0; i < h->n; i += stride) {
        if (i + stride/2 < h->n) {
            h->bin[i] *= scale;
            h->bin[i + stride/2] *= scale;
        } else {
            h->bin[i] *= scale;
        }
    }
}
