#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
__attribute__((aligned(32))) float wavreg1[128];
__attribute__((aligned(32))) float wavreg2[128];
int i;

void init_vars() {
    float *temp_out = (float *)aligned_alloc(32, 128 * sizeof(float));
    if (!temp_out) exit(1);
    for (int j = 0; j < 128; j++) {
        temp_out[j] = (float)(j % 17) * 0.5f;
        wavreg1[j] = (float)(j % 13) * 0.7f;
        wavreg2[j] = (float)(j % 11) * 0.9f;
    }
    out = temp_out;
    i = 0;
}