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
    // Variant 2: Consecutive array-like access using a temporary array to simulate batch accumulation
    // Though scalars are used, we simulate consecutive access by buffering operations
    // This changes access pattern to accumulate in blocks, modifying temporal locality

    const int BLOCK_SIZE = 4;
    double temp_psi_kp1[BLOCK_SIZE] = {0};
    double temp_psi_npkp1[BLOCK_SIZE] = {0};
    double temp_k_fact[BLOCK_SIZE] = {1};
    double temp_npk_fact_val[BLOCK_SIZE] = {1};
    double temp_yk[BLOCK_SIZE];
    double temp_sum[BLOCK_SIZE] = {0};

    temp_yk[0] = yk;

    for (k = 1; k < KMAX; k++) {
        int idx = (k - 1) % BLOCK_SIZE;

        // Reset block when full
        if (idx == 0 && k > 1) {
            // Flush accumulated block effects
            for (int i = 0; i < BLOCK_SIZE; i++) {
                psi_kp1 += temp_psi_kp1[i];
                psi_npkp1 += temp_psi_npkp1[i];
                k_fact *= temp_k_fact[i];
                npk_fact.val *= temp_npk_fact_val[i];
                yk = temp_yk[i];
                k_term = yk * (psi_kp1 + psi_npkp1 - 2. * ln_x_2) / (k_fact * npk_fact.val);
                sum2 += k_term;
            }
            // Reinitialize block buffers
            for (int i = 0; i < BLOCK_SIZE; i++) {
                temp_psi_kp1[i] = 0;
                temp_psi_npkp1[i] = 0;
                temp_k_fact[i] = 1;
                temp_npk_fact_val[i] = 1;
            }
            temp_yk[0] = yk;
        }

        // Fill buffer with next operation
        temp_psi_kp1[idx] = 1. / k;
        temp_psi_npkp1[idx] = 1. / (n + k);
        temp_k_fact[idx] = k;
        temp_npk_fact_val[idx] = n + k;
        temp_yk[idx] = (idx == 0) ? temp_yk[0] * -y : temp_yk[idx-1] * -y;

        // Final flush after loop not needed here since we update state incrementally in-block
    }

    // Final block flush
    int final_idx = (k - 1) % BLOCK_SIZE;
    for (int i = 0; i < final_idx; i++) {
        psi_kp1 += temp_psi_kp1[i];
        psi_npkp1 += temp_psi_npkp1[i];
        k_fact *= temp_k_fact[i];
        npk_fact.val *= temp_npk_fact_val[i];
        yk = temp_yk[i];
        k_term = yk * (psi_kp1 + psi_npkp1 - 2. * ln_x_2) / (k_fact * npk_fact.val);
        sum2 += k_term;
    }
}
