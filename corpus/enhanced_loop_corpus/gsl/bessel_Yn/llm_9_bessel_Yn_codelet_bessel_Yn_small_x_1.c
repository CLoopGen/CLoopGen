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
    // Variant 2: Reduced computational intensity with increased trip count via artificial expansion
    // Each original iteration is split into two, doubling the trip count but halving work per step
    int max_iter = 2 * KMAX;
    for (k = 1; k < max_iter; k++) {
        int orig_k = (k + 1) / 2;  // Map expanded index back to original k

        if (k % 2 == 1) {
            // First phase: update harmonic terms and factorials
            psi_kp1 += 1. / orig_k;
            psi_npkp1 += 1. / (n + orig_k);
            k_fact *= orig_k;
            npk_fact.val *= n + orig_k;
        } else {
            // Second phase: update yk and accumulate sum
            yk *= -y;
            k_term = yk * (psi_kp1 + psi_npkp1 - 2. * ln_x_2) / (k_fact * npk_fact.val);
            sum2 += k_term;
        }
    }
}
