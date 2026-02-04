#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float qu[2];
float mean_lsf_16k[16];
float *lsf_history;
float *isp_new;
int ma_pred;
int i;
float isp_q[16];

void init_vars() {
    for (int j = 0; j < 2; j++) {
        qu[j] = 0.5f + j * 0.1f;
    }
    for (int j = 0; j < 16; j++) {
        mean_lsf_16k[j] = 1.0f + j * 0.5f;
        isp_q[j] = 2.0f + j * 0.3f;
    }

    lsf_history = (float *)aligned_alloc(32, sizeof(float) * 16);
    isp_new = (float *)aligned_alloc(32, sizeof(float) * 16);

    if (!lsf_history || !isp_new) {
        exit(1);
    }

    for (int j = 0; j < 16; j++) {
        lsf_history[j] = 0.8f + j * 0.2f;
        isp_new[j] = 0.0f;
    }

    ma_pred = 1;
}