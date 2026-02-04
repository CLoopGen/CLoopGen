#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double * rlist;
size_t n;
size_t k;
double result_sum;

static double rlist_data[134217728 / sizeof(double)]; // ~128 MB

void init_vars() {
    n = sizeof(rlist_data) / sizeof(rlist_data[0]);
    rlist = rlist_data;
    result_sum = 0.0;
    k = 0;

    for (size_t i = 0; i < n; i++) {
        rlist[i] = (double)(i % 1000) + 0.5;
    }
}