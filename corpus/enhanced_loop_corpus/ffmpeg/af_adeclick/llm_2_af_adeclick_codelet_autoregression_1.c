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
    double epsilon = 0.;
    for (j = 0; j < i; j++)
        epsilon += a[j] * r[i - j];
    epsilon += r[i + 1];
    k[i] = -epsilon / alpha;
    alpha *= (1. - k[i] * k[i]);
    for (j = 0; j < i; j++)
        k[j] = a[j] + k[i] * a[i - j - 1];
    for (j = 0; j <= i; j++)
        a[j] = k[j];
}
}
