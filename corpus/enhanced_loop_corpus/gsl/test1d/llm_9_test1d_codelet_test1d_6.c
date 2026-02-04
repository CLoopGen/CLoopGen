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
extern gsl_histogram *h1;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 795; i++) {
        size_t idx = i / 2;
        double diff = h1->range[idx] - h->range[idx];
        if (diff * diff > 1e-12)
            status = 1;
    }
}
