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
for (i = 0; i <= ny; i++) {
    h->yrange[i] = yrange[i];
}

}
