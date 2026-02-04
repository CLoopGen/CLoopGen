#include <stdio.h>
#include <inttypes.h>

int m = 1200;
int n = 1400;
double float_n = 1400.0;
double data[1400][1200];
double mean[1200];
int i;
int j;

void init_vars() {
    for (int i_idx = 0; i_idx < 1400; i_idx++) {
        for (int j_idx = 0; j_idx < 1200; j_idx++) {
            data[i_idx][j_idx] = (double)(i_idx % 100) + (double)(j_idx % 50) / 100.0;
        }
    }
    for (int j_idx = 0; j_idx < 1200; j_idx++) {
        mean[j_idx] = 0.0;
    }
}