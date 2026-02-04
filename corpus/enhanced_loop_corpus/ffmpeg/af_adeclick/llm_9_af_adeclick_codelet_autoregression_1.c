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
for (i = 2; i < ar_order; i += 2) {
    double epsilon1 = 0., epsilon2 = 0.;
    for (j = 0; j < i - 1; j++) {
        epsilon1 += a[j] * r[i - 1 - j];
        epsilon2 += a[j] * r[i - j];
    }
    epsilon1 += r[i];
    epsilon2 += r[i + 1];
    k[i-1] = -epsilon1 / alpha;
    double temp_alpha = alpha;
    alpha *= (1. - k[i-1] * k[i-1]);
    k[i] = -epsilon2 / alpha;
    alpha *= (1. - k[i] * k[i]);
    for (j = i - 2; j >= 0; j--) {
        double temp_k = a[j] + k[i-1] * a[i - j - 2];
        k[j] = temp_k;
    }
    for (j = i - 1; j >= 0; j--) {
        k[j] = a[j] + k[i] * a[i - j - 1];
    }
    for (j = 0; j <= i; j++) {
        a[j] = k[j];
    }
}
}
