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
if (KMAX > 1) {
    // Unroll the first iteration manually and then run the loop from k=2 to reduce effective iterations with same logic
    k = 1;
    psi_kp1 += 1. / k;
    psi_npkp1 += 1. / (n + k);
    k_fact *= k;
    npk_fact.val *= n + k;
    yk *= y;
    k_term = yk * (psi_kp1 + psi_npkp1 - 2. * ln_x_2) / (k_fact * npk_fact.val);
    sum2 += k_term;

    for (k = 2; k < KMAX; k++) {
        psi_kp1 += 1. / k;
        psi_npkp1 += 1. / (n + k);
        k_fact *= k;
        npk_fact.val *= n + k;
        yk *= y;
        k_term = yk * (psi_kp1 + psi_npkp1 - 2. * ln_x_2) / (k_fact * npk_fact.val);
        sum2 += k_term;
    }
}
}
