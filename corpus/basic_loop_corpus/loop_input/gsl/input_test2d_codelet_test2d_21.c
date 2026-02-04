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

gsl_histogram2d *h;
size_t i;
size_t j;
size_t i1;
size_t i2;
size_t i3;
size_t i4;
size_t _usr_j1;
size_t j2;
size_t j3;
size_t j4;
double expected;
int status;

#define j1 _usr_j1

void init_vars() {
    i1 = 5;
    i2 = 8;
    i3 = 12;
    i4 = 15;
    _usr_j1 = 7;
    j2 = 10;
    j3 = 14;
    j4 = 18;

    h = (gsl_histogram2d *)malloc(sizeof(gsl_histogram2d));
    h->nx = 17;
    h->ny = 23;
    
    h->xrange = (double *)calloc(18, sizeof(double));
    h->yrange = (double *)calloc(24, sizeof(double));
    h->bin = (double *)calloc(17 * 23, sizeof(double));

    for (size_t i_idx = 0; i_idx < 17; i_idx++) {
        for (size_t j_idx = 0; j_idx < 23; j_idx++) {
            if (i_idx == i1 && j_idx == j1) {
                h->bin[i_idx * 23 + j_idx] = 1.0;
            } else if (i_idx == i2 && j_idx == j2) {
                h->bin[i_idx * 23 + j_idx] = 2.0;
            } else if (i_idx == i3 && j_idx == j3) {
                h->bin[i_idx * 23 + j_idx] = 3.0;
            } else if (i_idx == i4 && j_idx == j4) {
                h->bin[i_idx * 23 + j_idx] = 4.0;
            } else {
                h->bin[i_idx * 23 + j_idx] = 0.0;
            }
        }
    }

    expected = 0.0;
    status = 0;
}