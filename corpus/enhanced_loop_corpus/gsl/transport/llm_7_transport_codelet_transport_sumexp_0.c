#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int numexp;
extern  int order;
extern  double t;
extern double x;
extern double rk;
extern double sumexp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (k = 1; k <= numexp; k++) {
        double sum2 = 1.;
        double xk_base = 1. / (rk * x);
        double accum = 0.;
        int j;
        for (j = 1; j <= order; j++) {
            double xk = xk_base * j; // Eliminate recurrence in xk; now computed directly
            accum = accum + sum2 * xk; // Accumulate product terms
            sum2 = accum + 1.; // Introduce dependence of sum2 on accum — creates loop-carried RAW/WAW
        }
        sumexp += accum * t;
        sum2 = 0.; // Local write with no carry-out, breaking previous outer-loop dependency on sum2
        rk = rk - 1.;
    }
}
