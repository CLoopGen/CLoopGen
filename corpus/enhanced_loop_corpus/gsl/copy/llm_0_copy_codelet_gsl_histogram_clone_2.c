#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern  gsl_histogram *src;
extern size_t n;
extern size_t i;
extern gsl_histogram *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < n; j += 2) {
        if (j + 1 < n) {
            h->bin[j] = src->bin[j];
            h->bin[j + 1] = src->bin[j + 1];
        } else {
            h->bin[j] = src->bin[j];
        }
    }
}
