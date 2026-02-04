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

extern gsl_histogram2d *h;
extern gsl_histogram2d *h1;
extern gsl_histogram2d *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t length = 107 * 239;
    size_t stride = 4;
    size_t remainder = length % stride;
    
    size_t i = 0;
    for (; i < length - remainder; i += stride) {
        if (h1->bin[i]     != g->bin[i]     - h->bin[i])     status = 1;
        if (h1->bin[i + 1] != g->bin[i + 1] - h->bin[i + 1]) status = 1;
        if (h1->bin[i + 2] != g->bin[i + 2] - h->bin[i + 2]) status = 1;
        if (h1->bin[i + 3] != g->bin[i + 3] - h->bin[i + 3]) status = 1;
    }
    for (; i < length; i++) {
        if (h1->bin[i] != g->bin[i] - h->bin[i])
            status = 1;
    }
}
