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
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            double dn1 = w->dsum[i] * 2.2204460492503131E-16 * array[i];
            double dn2 = w->dsum[i + 1] * 2.2204460492503131E-16 * array[i + 1];
            variance += dn1 * dn1 + dn2 * dn2;
        } else {
            double dn = w->dsum[i] * 2.2204460492503131E-16 * array[i];
            variance += dn * dn;
        }
    }
}
