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
    size_t block_size = 4;
    size_t total = nx * ny;
    for (i = 0; i < total; i += block_size) {
        for (size_t j = 0; j < block_size && (i + j) < total; ++j) {
            h->bin[i + j] = src->bin[i + j] * 1.0;
        }
    }
}
