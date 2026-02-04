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
        double xk = 1. / (rk * x);
        double temp_sum = 0.;
        int j;
        for (j = 1; j <= order; j++) {
            temp_sum += sum2 * xk + 1.;
            sum2 += 0.5; // Introduces WAW dependency on sum2 within inner loop
            xk *= 1.1;  // Modifies xk in each iteration, creating loop-carried RAW dependency
        }
        sumexp = sumexp * t + temp_sum;
        rk -= 1.;
    }
}
