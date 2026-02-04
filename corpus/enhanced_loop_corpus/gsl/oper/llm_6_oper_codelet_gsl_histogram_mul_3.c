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
    double *bin1 = h1->bin;
    double *bin2 = h2->bin;
    size_t n = h1->n;
    for (i = 0; i < n; i++) {
        double temp = bin1[i] * bin2[i];
        bin1[i] = temp;
    }
}
