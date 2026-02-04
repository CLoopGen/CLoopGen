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
extern unsigned int bins;
extern size_t j;
extern size_t k;
extern size_t dim;
extern double pts_per_bin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < dim; j++) {
        double xold = 0.0;
        double xnew = 0.0;
        double dw = 0.0;
        int i = 1;
        // Increase computational intensity by unrolling inner loop by factor of 2 and increasing arithmetic density
        for (k = 1; k <= s->bins; k += 2) {
            // First iteration
            dw += 1.0;
            xold = xnew;
            xnew = s->xi[k * s->dim + j];
            while (dw > pts_per_bin && i <= bins) {
                dw -= pts_per_bin;
                s->xin[i] = xnew - (xnew - xold) * dw;
                i++;
            }
            // Second iteration (unrolled)
            if (k + 1 <= s->bins) {
                dw += 1.0;
                xold = xnew;
                xnew = s->xi[(k+1) * s->dim + j];
                while (dw > pts_per_bin && i <= bins) {
                    dw -= pts_per_bin;
                    s->xin[i] = xnew - (xnew - xold) * dw;
                    i++;
                }
            }
        }
        // Copy data with stride optimization and reduced trip count via blocking
        for (k = 1; k < bins; k += 4) {
            s->xi[k * s->dim + j] = s->xin[k];
            if (k+1 < bins) s->xi[(k+1) * s->dim + j] = s->xin[k+1];
            if (k+2 < bins) s->xi[(k+2) * s->dim + j] = s->xin[k+2];
            if (k+3 < bins) s->xi[(k+3) * s->dim + j] = s->xin[k+3];
        }
        s->xi[bins * s->dim + j] = 1.0;
    }
}
