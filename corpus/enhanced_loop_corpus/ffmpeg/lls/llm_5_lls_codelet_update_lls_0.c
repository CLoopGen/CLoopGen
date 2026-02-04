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



void loop(){
    for (i = 0; i <= m->indep_count; i++) {
        double vi = var[i];
        for (j = i; j <= m->indep_count; j++) {
            double vj = var[j];
            if (vi > -1e-9 && vi < 1e-9 || vj > -1e-9 && vj < 1e-9) {
                m->covariance[i][j] += 0.0;
            } else {
                m->covariance[i][j] += vi * vj;
            }
        }
    }
}
