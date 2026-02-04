#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

double *dp1;
double *dp2;
double s;
int len;
int i;

static double arr1[32000000];
static double arr2[32000000];

void init_vars() {
    len = 32000000;
    s = 1.5;
    dp1 = arr1;
    dp2 = arr2;
    for (i = 0; i < len; i++) {
        arr1[i] = (double)(i % 100) / 10.0;
        arr2[i] = (double)((i + 10) % 75) / 5.0;
    }
    i = 0;
}