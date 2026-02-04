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



void loop() {
    // Variant 2: Consecutive (forward) traversal with index remapping to simulate reversed access
    // Original loop goes from nexp down to 1; now go forward 1 to nexp with inverted index usage
    int j;
    int total_iters = nexp;

    for (j = 1; j <= total_iters; j++) {
        i = nexp - j + 1;  // Reverse mapping: simulate descending index

        sum *= ex;
        sum += (1. + 2. / xk + 2. / (xk * xk)) / rk;
        rk -= 1.;
        xk -= x;
    }
}
