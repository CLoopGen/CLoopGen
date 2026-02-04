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
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            h->bin[i] = src->bin[i] * 1.0;
            h->bin[i + 1] = src->bin[i + 1] * 1.0;
        } else {
            h->bin[i] = src->bin[i] * 1.0;
        }
    }
}
