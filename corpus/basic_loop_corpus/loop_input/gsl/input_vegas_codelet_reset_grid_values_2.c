#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

gsl_monte_vegas_state *s;
size_t i;
size_t j;
size_t dim;
size_t bins;

void init_vars() {
    dim = 8;
    bins = (1 << 20) / sizeof(double) / dim;  // ~1MB of data for d array
    if (bins == 0) bins = 1;

    s = (gsl_monte_vegas_state*)calloc(1, sizeof(gsl_monte_vegas_state));
    s->dim = dim;
    s->bins = bins;
    s->bins_max = bins;
    s->d = (double*)calloc(bins * dim, sizeof(double));
    s->xi = (double*)calloc(bins * dim, sizeof(double));
    s->xin = (double*)calloc(bins, sizeof(double));
    s->delx = (double*)calloc(dim, sizeof(double));
    s->weight = (double*)calloc(dim, sizeof(double));
    s->x = (double*)calloc(dim, sizeof(double));
    s->bin = (int*)calloc(dim, sizeof(int));
    s->box = (int*)calloc(1, sizeof(int));
    s->alpha = 1.5;
    s->mode = 0;
    s->verbose = 0;
    s->iterations = 0;
    s->stage = 0;
    s->jac = 1.0;
    s->wtd_int_sum = 0.0;
    s->sum_wgts = 0.0;
    s->chi_sum = 0.0;
    s->chisq = 0.0;
    s->result = 0.0;
    s->sigma = 0.0;
    s->it_start = 0;
    s->it_num = 0;
    s->samples = 0;
    s->calls_per_box = 0;
    s->ostream = NULL;
}