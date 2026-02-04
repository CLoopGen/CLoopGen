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
    for (k = 2; k <= n; k += 2) {
        double fac1 = (n - k + 1.) / (k * y);
        double fac2 = (n - k - 0.) / ((k + 1) * y);
        a[k] = 0.5 * fac1 * a[k - 1];
        b[k] = fac1 * b[k - 1];
        if (k + 1 <= n) {
            a[k + 1] = 0.5 * fac2 * a[k];
            b[k + 1] = fac2 * b[k];
        }
    }
}
