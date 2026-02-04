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
extern  double xmean;
extern  double ymean;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern size_t j;
extern long double wcovariance;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < ny; j += 2) {
        for (i = 0; i < nx; i += 2) {
            double xi1 = (h->xrange[i + 1] + h->xrange[i]) / 2. - xmean;
            double yj1 = (h->yrange[j + 1] + h->yrange[j]) / 2. - ymean;
            double wij1 = h->bin[i * ny + j];
            if (wij1 > 0) {
                W += wij1;
                wcovariance += ((xi1 * yj1) - wcovariance) * (wij1 / W);
            }
            if (i + 1 < nx) {
                double xi2 = (h->xrange[i + 2] + h->xrange[i + 1]) / 2. - xmean;
                double wij2 = h->bin[(i + 1) * ny + j];
                if (wij2 > 0) {
                    W += wij2;
                    wcovariance += ((xi2 * yj1) - wcovariance) * (wij2 / W);
                }
            }
            if (j + 1 < ny) {
                double yj2 = (h->yrange[j + 2] + h->yrange[j + 1]) / 2. - ymean;
                double wij3 = h->bin[i * ny + (j + 1)];
                if (wij3 > 0) {
                    W += wij3;
                    wcovariance += ((xi1 * yj2) - wcovariance) * (wij3 / W);
                }
            }
            if (i + 1 < nx && j + 1 < ny) {
                double xi2 = (h->xrange[i + 2] + h->xrange[i + 1]) / 2. - xmean;
                double yj2 = (h->yrange[j + 2] + h->yrange[j + 1]) / 2. - ymean;
                double wij4 = h->bin[(i + 1) * ny + (j + 1)];
                if (wij4 > 0) {
                    W += wij4;
                    wcovariance += ((xi2 * yj2) - wcovariance) * (wij4 / W);
                }
            }
        }
    }
}
