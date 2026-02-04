#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

extern  gsl_histogram2d *src;
extern size_t nx;
extern size_t ny;
extern size_t i;
extern gsl_histogram2d *h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *h_bin = h->bin;
    double *src_bin = src->bin;
    size_t total = nx * ny;
    for (i = 0; i < total; i += 2) {
        h_bin[i] = src_bin[i];
        if (i + 1 < total) {
            h_bin[i + 1] = src_bin[i + 1];
        }
    }
}
