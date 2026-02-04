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

extern gsl_monte_vegas_state *s;
extern double xl[];
extern double xu[];
extern size_t dim;
extern size_t j;
extern double vol;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t unroll_factor = 4;
    size_t remainder = dim % unroll_factor;
    
    // Fully unrolled main loop for computational intensity increase
    for (j = 0; j < dim - remainder; j += unroll_factor) {
        double dx0 = xu[j]     - xl[j];
        double dx1 = xu[j + 1] - xl[j + 1];
        double dx2 = xu[j + 2] - xl[j + 2];
        double dx3 = xu[j + 3] - xl[j + 3];

        s->delx[j]     = dx0; vol *= dx0;
        s->delx[j + 1] = dx1; vol *= dx1;
        s->delx[j + 2] = dx2; vol *= dx2;
        s->delx[j + 3] = dx3; vol *= dx3;

        ((s)->xi[(0) * (s)->dim + (j)])     = 0.; ((s)->xi[(1) * (s)->dim + (j)])     = 1.;
        ((s)->xi[(0) * (s)->dim + (j + 1)]) = 0.; ((s)->xi[(1) * (s)->dim + (j + 1)]) = 1.;
        ((s)->xi[(0) * (s)->dim + (j + 2)]) = 0.; ((s)->xi[(1) * (s)->dim + (j + 2)]) = 1.;
        ((s)->xi[(0) * (s)->dim + (j + 3)]) = 0.; ((s)->xi[(1) * (s)->dim + (j + 3)]) = 1.;
    }

    // Handle remaining iterations
    for (; j < dim; j++) {
        double dx = xu[j] - xl[j];
        s->delx[j] = dx;
        vol *= dx;
        ((s)->xi[(0) * (s)->dim + (j)]) = 0.;
        ((s)->xi[(1) * (s)->dim + (j)]) = 1.;
    }
}
