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
if (n >= 1) {
    for (k = 1; k <= n; ++k) {
        double fac = (n - k + 1.) / (k * y);
        a[k] = 0.5 * fac * a[k - 1];
        b[k] = fac * b[k - 1];
    }
}
// Outer conditional simulates reduced effective loop nesting depth by guarding entry
// Though single loop remains, control structure depth is altered
}
