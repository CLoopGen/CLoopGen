#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float lsf_no_r[10];
int16_t lsf_r[10];
float lsf_q[10];
int i;

void init_vars() {
    for (i = 0; i < 10; i++) {
        lsf_no_r[i] = (float)(rand() % 1000) / 100.0f;
        lsf_r[i] = (int16_t)(rand() % 32768);
        lsf_q[i] = 0.0f;
    }
    i = 0;
}