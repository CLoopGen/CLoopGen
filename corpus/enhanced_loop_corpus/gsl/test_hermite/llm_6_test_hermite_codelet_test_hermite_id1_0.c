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
    double prev_a = a[0];
    double prev_b = b[0];
    for (k = 1; k <= n; ++k) {
        double fac = (n - k + 1.) / (k * y);
        double temp_a = 0.5 * fac * prev_a;
        double temp_b = fac * prev_b;
        prev_a = temp_a;
        prev_b = temp_b;
        a[k] = temp_a;
        b[k] = temp_b;
    }
}
