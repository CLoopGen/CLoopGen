#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float isf[20] = {0};
float diff_isf[14] = {0};
float scale = 1.5f;
int i;
int j;

void init_vars() {
    for (int idx = 0; idx < 20; idx++) {
        isf[idx] = (float)(idx * 2);
    }
    scale = 0.5f;
    i = 0;
    j = 0;
}