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
for (i = 0; i < 107 * 239; i++) {
    if (h1->bin[i] != g->bin[i] + h->bin[i])
        status = 1;
}

}
