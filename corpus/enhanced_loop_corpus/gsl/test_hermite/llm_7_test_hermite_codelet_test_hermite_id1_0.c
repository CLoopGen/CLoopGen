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
    double accum = 1.0;
    for (k = 1; k <= n; ++k) {
        double fac = (n - k + 1.) / (k * y);
        accum *= fac;
        a[k] = 0.5 * accum * a[0];
        b[k] = accum * b[0];
    }
}
