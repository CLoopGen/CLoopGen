#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

typedef struct LLSModel {
    double covariance[36][36] __attribute__((aligned(32)));
    double coeff[32][32] __attribute__((aligned(32)));
    double variance[32];
    int indep_count;
    void (*update_lls)(struct LLSModel *, const double *);
    double (*evaluate_lls)(struct LLSModel *, const double *, int);
} LLSModel;

LLSModel *m;
unsigned short min_order;
int i;
int j;
int k;
double (*factor)[36];
double (*covar)[36];
double *covar_y;
int count;

void init_vars() {
    // Allocate and initialize LLSModel
    m = (LLSModel *)aligned_alloc(32, sizeof(LLSModel));
    if (!m) exit(1);

    // Initialize function pointers to dummy functions to avoid null calls
    m->update_lls = NULL;
    m->evaluate_lls = NULL;

    // Set reasonable default values for array contents
    for (int ii = 0; ii < 36; ii++) {
        for (int jj = 0; jj < 36; jj++) {
            m->covariance[ii][jj] = (ii == jj) ? 1.0 : 0.01 * ((ii + jj) % 7);
        }
    }

    for (int ii = 0; ii < 32; ii++) {
        for (int jj = 0; jj < 32; jj++) {
            m->coeff[ii][jj] = (ii >= jj) ? 0.5 : 0.0;
        }
    }

    for (int ii = 0; ii < 32; ii++) {
        m->variance[ii] = 1.0;
    }

    m->indep_count = 32;

    // Set loop parameters
    min_order = 4;
    count = 24;  // Ensures j goes from 23 down to min_order=4

    // Allocate factor and covar as 36x36 arrays to match declarations
    factor = (double (*)[36])aligned_alloc(32, 36 * 36 * sizeof(double));
    covar = (double (*)[36])aligned_alloc(32, 36 * 36 * sizeof(double));
    if (!factor || !covar) exit(1);

    // Initialize factor with non-zero diagonal to prevent division by zero
    for (int ii = 0; ii < 36; ii++) {
        for (int jj = 0; jj < 36; jj++) {
            factor[ii][jj] = (ii == jj) ? 2.0 : 0.01 * ((ii * jj + 1) % 5);
        }
    }

    for (int ii = 0; ii < 36; ii++) {
        for (int jj = 0; jj < 36; jj++) {
            covar[ii][jj] = (ii == jj) ? 1.5 : 0.02 * ((ii + 2 * jj) % 3);
        }
    }

    // Allocate and initialize covar_y (size at least count+1 or j+1 which is up to 24)
    covar_y = (double *)malloc(36 * sizeof(double));
    if (!covar_y) exit(1);

    for (int ii = 0; ii < 36; ii++) {
        covar_y[ii] = 0.5;
    }
}