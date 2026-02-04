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

extern  gsl_histogram2d *h;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern size_t j;
extern long double wmean;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nx; i++) {
        double xi = (h->xrange[i + 1] + h->xrange[i]) / 2.;
        double wi = 0;
        size_t j_start = 0;
        size_t j_end = ny;
        // Introduce partitioned reduction with temporary accumulation to alter RAW/WAW dependencies
        double wi_local = 0;
        for (j = j_start; j < j_end; j++) {
            double wij = h->bin[i * ny + j];
            wi_local += (wij > 0) ? wij : 0;
        }
        wi = wi_local;
        if (wi > 0) {
            long double temp = xi - wmean;
            W += wi;
            wmean += temp * (wi / W);
        }
    }
}
