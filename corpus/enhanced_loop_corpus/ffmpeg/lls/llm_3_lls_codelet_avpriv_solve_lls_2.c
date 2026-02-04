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
extern unsigned short min_order;
extern int i;
extern int j;
extern int k;
extern double (*factor)[36];
extern double (*covar)[36];
extern double *covar_y;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t stride = 36;
double *base_coeff_row = &m->coeff[0][0];
double *base_factor = (double *)factor;
double *base_covar = (double *)covar;

for (j = count - 1; j >= min_order; j--) {
    for (i = j; i >= 0; i--) {
        double sum = base_coeff_row[i]; 
        for (k = i + 1; k <= j; k++) {
            double *coeff_addr = base_coeff_row + j * stride + k;
            double *factor_addr = base_factor + k * stride + i;
            sum -= (*factor_addr) * (*coeff_addr);
        }
        double *dest_addr = base_coeff_row + j * stride + i;
        *dest_addr = sum / (*(base_factor + i * stride + i));
    }

    m->variance[j] = covar_y[0];
    for (i = 0; i <= j; i++) {
        double sum = m->coeff[j][i] * (*(base_covar + i * stride + i)) - 2 * covar_y[i + 1];
        for (k = 0; k < i; k++) {
            double *covar_addr = base_covar + k * stride + i;
            sum += 2 * m->coeff[j][k] * (*covar_addr);
        }
        m->variance[j] += m->coeff[j][i] * sum;
    }
}
}
