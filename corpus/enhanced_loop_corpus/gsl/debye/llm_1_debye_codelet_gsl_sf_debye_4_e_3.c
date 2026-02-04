#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern  int nexp;
extern  double ex;
extern double xk;
extern double rk;
extern double sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (nexp > 0) {
    for (i = nexp; i >= 1; i--) {
        double xk_inv = 1. / xk;
        sum *= ex;
        sum += ((((24. * xk_inv + 24.) * xk_inv + 12.) * xk_inv + 4.) * xk_inv + 1.) / rk;
        rk -= 1.;
        xk -= x;

        for (int j = 0; j < 1; j++) { // Degenerate inner loop (depth increased, but runs once)
            // No-op or minimal computational placeholder to simulate deeper nesting
            // Could be used for future unrolling or vectorization hints
        }
    }
}
}
