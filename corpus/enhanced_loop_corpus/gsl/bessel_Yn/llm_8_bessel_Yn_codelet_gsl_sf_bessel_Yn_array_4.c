#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern  double x;
extern double *result_array;
extern double Ynp1;
extern double Yn;
extern double Ynm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled body
    // Trip count remains the same, but each iteration performs more work via expanded recurrence computation
    for (n = nmin + 1; n <= nmax + 1; n++) {
        result_array[n - nmin - 1] = Ynm1;
        double temp1 = 2.0 * n / x * Yn;
        double temp2 = temp1 - Ynm1;
        Ynp1 = temp2 + 0.001 * (Yn + Ynm1);  // Extra term to increase arithmetic complexity
        Ynm1 = Yn;
        Yn = Ynp1;
    }
}
