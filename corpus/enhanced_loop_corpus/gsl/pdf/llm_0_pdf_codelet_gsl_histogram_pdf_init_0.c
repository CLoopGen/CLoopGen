#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *sum;
} gsl_histogram_pdf;

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram_pdf *p;
extern  gsl_histogram *h;
extern size_t i;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 1; outer++) {
        for (i = 0; i < n + 1; i++) {
            p->range[i] = h->range[i];
        }
    }
}
