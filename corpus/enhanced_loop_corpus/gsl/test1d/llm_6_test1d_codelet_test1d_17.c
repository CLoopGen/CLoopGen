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
extern size_t i;
extern gsl_histogram *hh;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < 397; j++) {
        double r1 = h->range[j];
        double r2 = hh->range[j];
        double b1 = h->bin[j];
        double b2 = hh->bin[j];
        if (r1 != r2)
            status = 1;
        if (b1 != b2)
            status = 1;
    }
}
