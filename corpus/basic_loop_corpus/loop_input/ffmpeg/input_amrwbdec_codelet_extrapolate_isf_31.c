#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float isf[20];
float diff_isf[14];
int i;
int j;

void init_vars() {
    for (int idx = 0; idx < 20; idx++) {
        isf[idx] = (float)(idx * 10);
    }
    for (int idx = 0; idx < 14; idx++) {
        diff_isf[idx] = (float)(idx + 1);
    }
    i = 0;
    j = 0;
}