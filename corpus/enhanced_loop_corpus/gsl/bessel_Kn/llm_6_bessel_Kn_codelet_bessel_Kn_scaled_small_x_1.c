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
for (k = 1; k < KMAX; k++) {
    double temp_psi_kp1 = psi_kp1 + 1. / k;
    double temp_psi_npkp1 = psi_npkp1 + 1. / (n + k);
    double temp_k_fact = k_fact * k;
    double temp_npk_fact_val = npk_fact.val * (n + k);
    double temp_yk = yk * y;
    double temp_k_term = temp_yk * (temp_psi_kp1 + temp_psi_npkp1 - 2. * ln_x_2) / (temp_k_fact * temp_npk_fact_val);
    sum2 += temp_k_term;

    psi_kp1 = temp_psi_kp1;
    psi_npkp1 = temp_psi_npkp1;
    k_fact = temp_k_fact;
    npk_fact.val = temp_npk_fact_val;
    yk = temp_yk;
}
}
