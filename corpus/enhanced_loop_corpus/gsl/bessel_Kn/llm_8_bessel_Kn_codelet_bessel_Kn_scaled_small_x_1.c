#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_sf_result_struct {
    double val;
    double err;
};


typedef struct gsl_sf_result_struct gsl_sf_result;

extern  int n;
extern int k;
extern double y;
extern double ln_x_2;
extern double k_term;
extern double sum2;
extern  int KMAX;
extern gsl_sf_result npk_fact;
extern double yk;
extern double k_fact;
extern double psi_kp1;
extern double psi_npkp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k < KMAX; k += 2) {
    psi_kp1 += 1. / k;
    if (k + 1 < KMAX) {
        psi_kp1 += 1. / (k + 1);
    }
    psi_npkp1 += 1. / (n + k);
    if (k + 1 < KMAX) {
        psi_npkp1 += 1. / (n + k + 1);
    }
    k_fact *= k;
    if (k + 1 < KMAX) {
        k_fact *= (k + 1);
    }
    npk_fact.val *= n + k;
    if (k + 1 < KMAX) {
        npk_fact.val *= n + k + 1;
    }
    yk *= y;
    if (k + 1 < KMAX) {
        yk *= y;
    }
    k_term = yk * (psi_kp1 + psi_npkp1 - 2. * ln_x_2) / (k_fact * npk_fact.val);
    sum2 += k_term;
}
}
