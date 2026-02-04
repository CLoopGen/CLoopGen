#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h1;
extern  gsl_histogram *h2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h1->n > 0) {
        i = 0;
        for (size_t outer = 0; outer < h1->n; outer++) {
            h1->bin[i] += h2->bin[i];
            i++;
        }
    }
}
