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
extern double mean;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        i = 0;
        for (; i < n; ) {
            sum += (h->bin[i] / mean) / n;
            p->sum[i + 1] = sum;
            i++;
        }
    }
}
