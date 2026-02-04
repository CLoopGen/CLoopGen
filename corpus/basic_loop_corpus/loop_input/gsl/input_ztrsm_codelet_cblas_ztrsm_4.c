#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

void *B;
int ldb;
int i;
int j;
int n1;
int n2;
double alpha_real;
double alpha_imag;

static double B_data[131072]; // 1MB of data (131072 * 8 bytes per double)

void init_vars() {
    const size_t total_elements = 131072;
    for (size_t idx = 0; idx < total_elements; ++idx) {
        B_data[idx] = (double)(idx % 128) / 10.0;
    }

    B = (void*)B_data;

    alpha_real = 1.5;
    alpha_imag = 0.8;

    n1 = 256;
    n2 = 256;
    ldb = 256;

    i = 0;
    j = 0;
}