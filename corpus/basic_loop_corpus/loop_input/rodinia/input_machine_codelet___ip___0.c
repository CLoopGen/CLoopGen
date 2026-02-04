#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double *dp1;
double *dp2;
int len;
int i;
double sum;

static double dp1_storage[32000000];
static double dp2_storage[32000000];

void init_vars() {
    len = 32000000;
    dp1 = dp1_storage;
    dp2 = dp2_storage;
    sum = 0.0;
    i = 0;

    for (int j = 0; j < len; j++) {
        dp1[j] = (double)(j % 1000) / 100.0;
        dp2[j] = (double)((j + 5) % 999) / 101.0;
    }
}