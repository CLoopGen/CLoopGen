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
    // Variant 1: Strided memory access pattern simulation via unrolling by 2
    // This variant processes two iterations per loop cycle to create a strided effect
    int k_step;
    for (k = 1; k < KMAX; k += 2) {
        // First iteration of the stride
        psi_kp1 += 1. / k;
        psi_npkp1 += 1. / (n + k);
        k_fact *= k;
        npk_fact.val *= n + k;
        yk *= -y;
        k_term = yk * (psi_kp1 + psi_npkp1 - 2. * ln_x_2) / (k_fact * npk_fact.val);
        sum2 += k_term;

        // Second iteration (if within bounds)
        k_step = k + 1;
        if (k_step < KMAX) {
            psi_kp1 += 1. / k_step;
            psi_npkp1 += 1. / (n + k_step);
            k_fact *= k_step;
            npk_fact.val *= n + k_step;
            yk *= -y;
            k_term = yk * (psi_kp1 + psi_npkp1 - 2. * ln_x_2) / (k_fact * npk_fact.val);
            sum2 += k_term;
        }
    }
}
