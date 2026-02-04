#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t dim;
    size_t bins_max;
    unsigned int bins;
    unsigned int boxes;
    double *xi;
    double *xin;
    double *delx;
    double *weight;
    double vol;
    double *x;
    int *bin;
    int *box;
    double *d;
    double alpha;
    int mode;
    int verbose;
    unsigned int iterations;
    int stage;
    double jac;
    double wtd_int_sum;
    double sum_wgts;
    double chi_sum;
    double chisq;
    double result;
    double sigma;
    unsigned int it_start;
    unsigned int it_num;
    unsigned int samples;
    unsigned int calls_per_box;
    FILE *ostream;
} gsl_monte_vegas_state;

static double *xi_data;
static double *xin_data;

gsl_monte_vegas_state *s;
unsigned int bins;
size_t j;
size_t k;
size_t dim;
double pts_per_bin;

void init_vars() {
    dim = 10;
    bins = 128;
    pts_per_bin = 10.0;

    s = (gsl_monte_vegas_state*)calloc(1, sizeof(gsl_monte_vegas_state));
    s->dim = dim;
    s->bins = bins;
    s->bins_max = bins;
    s->xi = (double*)calloc((bins + 1) * dim, sizeof(double));
    s->xin = (double*)calloc(bins + 1, sizeof(double));

    xi_data = s->xi;
    xin_data = s->xin;

    for (size_t idx = 0; idx < (bins + 1) * dim; idx++) {
        xi_data[idx] = (double)(idx % 100) / 100.0;
    }
    for (size_t idx = 0; idx <= bins; idx++) {
        xin_data[idx] = 0.0;
    }

    j = 0;
    k = 0;
}