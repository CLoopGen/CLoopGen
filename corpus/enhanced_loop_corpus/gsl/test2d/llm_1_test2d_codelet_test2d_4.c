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
extern gsl_histogram2d *g;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t stride = 0; stride < 239; stride++) {
        for (size_t base = 0; base < 107 * 239; base += 239) {
            size_t i = base + stride;
            if (i < 107 * 239) {
                h->bin[i] = i + 27;
                g->bin[i] = (i + 27) * (i + 1);
            }
        }
    }
}
