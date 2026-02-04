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
extern  double yrange[];
extern size_t i;
extern  size_t ny;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i <= ny; i++) {
        j = i + 1;
        if (j <= ny) {
            h->yrange[i] = yrange[j]; // Introduces RAW dependency: yrange[j] must be read before h->yrange[i] is written
        } else {
            h->yrange[i] = 0.0;
        }
    }
}
