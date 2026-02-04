#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float mean_lsf[10];
float *lsfnew;
float *lsf_history;
int i;
float lsf_tmp[10];

void init_vars() {
    lsfnew = (float*)aligned_alloc(32, sizeof(float) * 10);
    lsf_history = (float*)aligned_alloc(32, sizeof(float) * 10);

    for (i = 0; i < 10; i++) {
        mean_lsf[i] = 1.0f;
        lsf_tmp[i] = 2.0f;
        lsf_history[i] = 3.0f;
        lsfnew[i] = 0.0f;
    }
}