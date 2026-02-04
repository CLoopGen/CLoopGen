#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct LLSModel {
    double covariance[36][36] __attribute__((aligned(32)));
    double coeff[32][32] __attribute__((aligned(32)));
    double variance[32];
    int indep_count;
    void (*update_lls)(struct LLSModel *, const double *);
    double (*evaluate_lls)(struct LLSModel *, const double *, int);
} LLSModel;

extern LLSModel *m;
extern  double *var;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive (row-major flat) memory access with indirect indexing
    // Flatten the double loop into a single loop over a linear index,
    // computing valid (i,j) pairs such that i <= j and within bounds.
    int n = m->indep_count;
    int idx = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            // Access covariance as if it were a 1D array with stride 36
            double *base = &m->covariance[0][0];
            base[i * 36 + j] += var[i] * var[j];
        }
    }
}
