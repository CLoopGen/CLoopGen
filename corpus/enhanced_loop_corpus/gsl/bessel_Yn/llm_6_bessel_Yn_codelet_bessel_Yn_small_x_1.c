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
    double temp_psi_kp1 = psi_kp1;
    double temp_psi_npkp1 = psi_npkp1;
    double temp_k_fact = k_fact;
    double temp_npk_fact_val = npk_fact.val;
    double temp_yk = yk;
    double temp_sum2 = sum2;

    for (k = 1; k < KMAX; k++) {
        temp_psi_kp1 += 1. / k;
        temp_psi_npkp1 += 1. / (n + k);
        temp_k_fact *= k;
        temp_npk_fact_val *= n + k;
        temp_yk *= -y;

        double local_k_term = temp_yk * (temp_psi_kp1 + temp_psi_npkp1 - 2. * ln_x_2) / (temp_k_fact * temp_npk_fact_val);
        temp_sum2 += local_k_term;
    }

    // Update shared externs only after loop completes (eliminates loop-carried WAW and WAR dependencies)
    psi_kp1 = temp_psi_kp1;
    psi_npkp1 = temp_psi_npkp1;
    k_fact = temp_k_fact;
    npk_fact.val = temp_npk_fact_val;
    yk = temp_yk;
    sum2 = temp_sum2;
}
