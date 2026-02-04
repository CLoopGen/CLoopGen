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
    if (i % 2 == 0) {
        for (j = 0; j < i; j++)
            epsilon += a[j] * r[i - j];
        epsilon += r[i + 1];
        k[i] = -epsilon / alpha;
        alpha *= (1. - k[i] * k[i]);
        for (j = i - 1; j >= 0; j--)
            k[j] = a[j] + k[i] * a[i - j - 1];
        for (j = 0; j <= i; j++)
            a[j] = k[j];
    } else {
        epsilon = r[i + 1];
        for (j = 0; j < i; j += 2)
            if ((i - j) > 0)
                epsilon += a[j] * r[i - j];
        k[i] = (alpha != 0.0) ? -epsilon / alpha : 0.0;
        if (alpha > 1e-9)
            alpha *= (1. - k[i] * k[i]);
        for (j = i - 1; j >= 0; j--)
            k[j] = a[j] + k[i] * a[i - j - 1];
        for (j = 0; j <= i; j++)
            a[j] = k[j];
    }
}
}
