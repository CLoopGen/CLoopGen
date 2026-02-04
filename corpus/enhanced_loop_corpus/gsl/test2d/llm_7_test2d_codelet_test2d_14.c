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
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    status = 0;
    for (i = 0; i < 107 * 239; i += 2) {
        if (h->bin[i] != 0)
            status = 1;
        if (i + 1 < 107 * 239 && h->bin[i + 1] != 0)
            status = 1;
    }
}
