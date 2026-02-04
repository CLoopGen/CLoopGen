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
    double *b1 = h1->bin;
    double *b2 = h2->bin;
    size_t n = h1->n;
    for (i = 0; i < n; i++) {
        b1[i] = b1[i] + b2[i];
    }
}
