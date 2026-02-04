#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float diff_isf[14];
int i;

void init_vars() {
    for (int idx = 0; idx < 14; idx++) {
        diff_isf[idx] = 2.0f + (idx % 3) * 1.5f;
    }
    i = 0;
}