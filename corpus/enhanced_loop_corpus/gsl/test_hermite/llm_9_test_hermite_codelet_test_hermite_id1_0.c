#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double y;
extern double *a;
extern double *b;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k <= n; ++k) {
        double ratio = (double)(n - k + 1) / y;
        double inv_k = 1.0 / k;
        double fac = ratio * inv_k;
        double temp_a = a[k - 1] * 0.5;
        a[k] = fac * temp_a;
        b[k] = fac * b[k - 1];
    }
}
