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
    double temp_correction = 0.0;
    if (k > 5) {
        temp_correction = 1.0 / (k * k);
    }
    psi_kp1 += 1. / k + temp_correction;
    psi_npkp1 += 1. / (n + k);
    k_fact *= k;
    npk_fact.val *= n + k;
    yk *= y;
    k_term = yk * (psi_kp1 + psi_npkp1 - 2. * ln_x_2) / (k_fact * npk_fact.val);
    if (k_term >= 0) {
        sum2 += k_term;
    }
}
}
