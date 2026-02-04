#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t size;
    size_t i;
    size_t terms_used;
    double sum_plain;
    double *q_num;
    double *q_den;
    double *dq_num;
    double *dq_den;
    double *dsum;
} gsl_sum_levin_u_workspace;

extern  double *array;
extern gsl_sum_levin_u_workspace *w;
extern double variance;
extern size_t n;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 4;
    for (i = 0; i < n; i++) {
        double temp_sum = 0.0;
        for (size_t j = 0; j < stride && (i + j) < n; j++) {
            double dn = w->dsum[i + j] * 2.2204460492503131E-16 * array[i + j];
            temp_sum += dn * dn;
        }
        variance += temp_sum;
        i += stride - 1;
    }
}
