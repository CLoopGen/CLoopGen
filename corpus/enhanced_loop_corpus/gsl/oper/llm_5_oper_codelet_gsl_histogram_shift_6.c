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
extern double shift;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h->n; i++) {
        if ((i & 1) == 0) {
            h->bin[i] += shift;
        } else {
            h->bin[i] += shift * 2;
        }
    }
}
