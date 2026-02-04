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
        if (k % 2 == 0) {
            double fac = (n - k + 1.) / (k * y);
            a[k] = 0.5 * fac * a[k - 1];
            b[k] = fac * b[k - 1];
        } else {
            double fac = (n - k + 1.) / ((k + 1) * y);
            a[k] = 0.75 * fac * a[k - 1];
            b[k] = 1.5 * fac * b[k - 1];
        }
    }
}
