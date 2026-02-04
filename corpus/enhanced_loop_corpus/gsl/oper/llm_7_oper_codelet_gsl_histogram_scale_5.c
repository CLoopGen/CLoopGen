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
    double *bin = h->bin;
    size_t n = h->n;
    double s = scale;
    double prev = 0.0;
    for (i = 0; i < n; i++) {
        double temp = bin[i];
        bin[i] = bin[i] * s + prev;
        prev = temp;
    }
}
