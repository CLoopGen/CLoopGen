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

extern gsl_histogram2d *h1;
extern  gsl_histogram2d *h2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h1->nx > 0 && h1->ny > 0) {
        size_t total = h1->nx * h1->ny;
        for (size_t block = 0; block < total; block += 8) {
            for (size_t offset = 0; offset < 8; offset++) {
                size_t i = block + offset;
                if (i >= total) break;
                h1->bin[i] -= h2->bin[i];
            }
        }
    }
}
