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
for (j = 0; j < ny; j += 2) {
    double wj_total[2] = {0};
    for (i = 0; i < nx; i++) {
        double wij0 = h->bin[i * ny + j];
        if (wij0 > 0)
            wj_total[0] += wij0;
        if (j + 1 < ny) {
            double wij1 = h->bin[i * ny + j + 1];
            if (wij1 > 0)
                wj_total[1] += wij1;
        }
    }
    if (wj_total[0] > 0) {
        W += wj_total[0];
        wmean += ( (h->yrange[j + 1] + h->yrange[j]) / 2. - wmean ) * (wj_total[0] / W);
    }
    if (j + 1 < ny && wj_total[1] > 0) {
        W += wj_total[1];
        wmean += ( (h->yrange[j + 2] + h->yrange[j + 1]) / 2. - wmean ) * (wj_total[1] / W);
    }
}
}
