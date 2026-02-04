#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float isfp_inter[4] = {0.1f, 0.2f, 0.3f, 0.4f};

double isp_q[4][16];

double *isp4_past;

int i;
int k;

void init_vars() {
    size_t past_size = 16;
    isp4_past = (double *)aligned_alloc(32, past_size * sizeof(double));
    for (size_t idx = 0; idx < past_size; idx++) {
        isp4_past[idx] = (double)(idx + 1) * 0.5;
    }
    for (int k_idx = 0; k_idx < 4; k_idx++) {
        for (int i_idx = 0; i_idx < 16; i_idx++) {
            isp_q[k_idx][i_idx] = (double)(k_idx * 16 + i_idx + 1) * 1.1;
        }
    }
}