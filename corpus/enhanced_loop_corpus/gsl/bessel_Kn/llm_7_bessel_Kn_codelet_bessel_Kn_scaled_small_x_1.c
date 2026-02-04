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
double local_sum2 = sum2;
double local_psi_kp1 = psi_kp1;
double local_psi_npkp1 = psi_npkp1;
double local_k_fact = k_fact;
double local_npk_fact_val = npk_fact.val;
double local_yk = yk;

for (k = 1; k < KMAX; k++) {
    local_psi_kp1 += 1. / k;
    local_psi_npkp1 += 1. / (n + k);
    local_k_fact *= k;
    local_npk_fact_val *= n + k;
    local_yk *= y;
    double k_term = local_yk * (local_psi_kp1 + local_psi_npkp1 - 2. * ln_x_2) / (local_k_fact * local_npk_fact_val);
    local_sum2 += k_term;
}

sum2 = local_sum2;
psi_kp1 = local_psi_kp1;
psi_npkp1 = local_psi_npkp1;
k_fact = local_k_fact;
npk_fact.val = local_npk_fact_val;
yk = local_yk;
}
