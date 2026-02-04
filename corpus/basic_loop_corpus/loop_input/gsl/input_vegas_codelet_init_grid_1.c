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
double xl[1024];
double xu[1024];
size_t dim = 512;
size_t j;
double vol;

void init_vars() {
    s = (gsl_monte_vegas_state*)calloc(1, sizeof(gsl_monte_vegas_state));
    if (!s) exit(1);

    s->dim = dim;
    s->bins_max = 1024;
    s->bins = 16;
    s->boxes = 8;
    s->vol = 1.0;
    s->alpha = 1.5;
    s->mode = 0;
    s->verbose = 0;
    s->iterations = 1000;
    s->stage = 0;
    s->jac = 1.0;
    s->wtd_int_sum = 0.0;
    s->sum_wgts = 0.0;
    s->chi_sum = 0.0;
    s->chisq = 0.0;
    s->result = 0.0;
    s->sigma = 0.0;
    s->it_start = 0;
    s->it_num = 10;
    s->samples = 10000;
    s->calls_per_box = 1000;
    s->ostream = stdout;

    s->xi = (double*)calloc(2 * s->dim, sizeof(double));
    s->xin = (double*)calloc(s->dim, sizeof(double));
    s->delx = (double*)calloc(s->dim, sizeof(double));
    s->weight = (double*)calloc(s->dim, sizeof(double));
    s->x = (double*)calloc(s->dim, sizeof(double));
    s->bin = (int*)calloc(s->dim, sizeof(int));
    s->box = (int*)calloc(s->dim, sizeof(int));
    s->d = (double*)calloc(s->dim, sizeof(double));

    for (size_t i = 0; i < dim; i++) {
        xl[i] = 0.0;
        xu[i] = 1.0;
    }

    vol = 1.0;
}