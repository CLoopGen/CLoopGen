#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *sum;
} gsl_histogram2d_pdf;

typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

extern gsl_histogram2d_pdf *p;
extern  gsl_histogram2d *h;
extern size_t i;
extern  size_t n;
extern double mean;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reverse consecutive memory access – traverse arrays from end to beginning
    sum = 0.0; // Reset accumulator

    // Start from the last valid index and go backwards
    for (i = n; i > 0; --i) {
        size_t idx = i - 1; // Convert to zero-based index
        sum += (h->bin[idx] / mean) / n;
        p->sum[i] = sum; // p->sum[i] corresponds to cumulative sum at position i
    }
}
