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
extern  double *param;
extern int order;
extern int i;
extern double out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_out = 0.0;
    for (i = 0; i <= order; i++) {
        temp_out += param[i] * m->coeff[order][i];
    }
    out += temp_out;
}
