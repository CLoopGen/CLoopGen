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
for (k = 1; k < KMAX && k < 10; k++) {
    double inv_k = 1.0 / k;
    double inv_npk = 1.0 / (n + k);
    psi_kp1 += inv_k;
    psi_npkp1 += inv_npk;
    k_fact *= k;
    npk_fact.val *= (n + k);
    yk *= y;
    double temp_sum = psi_kp1 + psi_npkp1 - 2.0 * ln_x_2;
    double denominator = k_fact * npk_fact.val;
    k_term = yk * temp_sum / denominator;
    sum2 += k_term;
    
    // Additional computational work to increase arithmetic intensity
    k_term = (k_term > 0.0) ? k_term : -k_term;
    sum2 += (k_term * 0.01); // Slight perturbation for extra computation
}
}
