#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float diff_isf[14];
float diff_mean;
int i;

void init_vars() {
    for (int idx = 0; idx < 14; ++idx) {
        diff_isf[idx] = 1.0f + idx * 0.5f;
    }
    diff_mean = 0.0f;
    i = 0;
}