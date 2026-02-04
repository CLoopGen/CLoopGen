#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double V1inv[25];

double fx_data[40];

double c_data[5];

double *fx = fx_data;
double *c = c_data;
int i;
int j;

void init_vars() {
    for (int idx = 0; idx < 25; idx++) {
        V1inv[idx] = 1.0 / (1 + idx);
    }
    for (int idx = 0; idx < 40; idx++) {
        fx_data[idx] = idx * 0.5;
    }
    for (int idx = 0; idx < 5; idx++) {
        c_data[idx] = 0.0;
    }
    i = 0;
    j = 0;
}