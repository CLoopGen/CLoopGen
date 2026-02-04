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
        if (var[i] == 0.0) continue;
        for (j = i; j <= m->indep_count; j++) {
            if (var[j] != 0.0) {
                m->covariance[i][j] += var[i] * var[j];
            }
        }
    }
}
