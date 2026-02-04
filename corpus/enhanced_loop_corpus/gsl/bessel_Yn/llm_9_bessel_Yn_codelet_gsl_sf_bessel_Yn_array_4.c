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
    // Variant 2: Reduced trip count with stride-2 loop progression and simplified update
    // Lower computational load per total execution, but maintains loop structure
    for (n = nmin + 1; n <= nmax + 1; n += 2) {
        result_array[n - nmin - 1] = Ynm1;
        Ynp1 = -Ynm1 + 2. * n / x * Yn;
        Ynm1 = Yn;
        Yn = Ynp1;

        // Ensure array bounds still safe for next access if within range
        if (n + 1 <= nmax + 1) {
            result_array[n + 1 - nmin - 1] = Ynm1;
            double next_Ynp1 = -Ynm1 + 2. * (n + 1) / x * Yn;
            Ynm1 = Yn;
            Yn = next_Ynp1;
        }
    }
}
