#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ar_order;
extern double *k;
extern double *r;
extern double *a;
extern double alpha;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < ar_order; i++) {
    double epsilon = r[i + 1];
    for (j = 0; j < i; j++)
        epsilon += a[j] * r[i - j];
    k[i] = -epsilon / alpha;
    double k_sq = k[i] * k[i];
    alpha *= (1. - k_sq);
    for (j = 0; j < i; j++)
        k[j] = a[j] + k[i] * a[i - j - 1];
    for (j = 0; j <= i; j++)
        a[j] = k[j];
}
}
