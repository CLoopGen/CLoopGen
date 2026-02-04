#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct LLSModel {
    double covariance[36][36] __attribute__((aligned(32)));
    double coeff[32][32] __attribute__((aligned(32)));
    double variance[32];
    int indep_count;
    void (*update_lls)(struct LLSModel *, const double *);
    double (*evaluate_lls)(struct LLSModel *, const double *, int);
} LLSModel;

LLSModel *m;
double *var;
int i;
int j;

void init_vars() {
    m = aligned_alloc(32, sizeof(LLSModel));
    memset(m, 0, sizeof(LLSModel));
    
    m->indep_count = 35; 
    
    var = aligned_alloc(32, 36 * sizeof(double));
    memset(var, 0, 36 * sizeof(double));
    
    for (int idx = 0; idx <= m->indep_count; idx++) {
        var[idx] = 1.0 + idx * 0.1;
    }
    
    for (int ii = 0; ii <= m->indep_count; ii++) {
        for (int jj = 0; jj <= m->indep_count; jj++) {
            m->covariance[ii][jj] = 0.0;
        }
    }
}