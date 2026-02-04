#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern  double two_over_x;
extern double Inp1;
extern double In;
extern double Inm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via step subdivision
    // Each original iteration is split into two, halving the effective step but adding conditional logic
    // Arithmetic operations per data point are preserved, but overhead increases

    for (int i = 2 * nmax; i >= 2 * nmin; i--) {
        n = i / 2;  // Map expanded index back to original n values

        if (i % 2 == 0) {
            // Only compute recurrence on even steps (original indices)
            result_array[n - nmin] = In;
            double temp = Inp1 + n * two_over_x * In;
            Inp1 = In;
            In = temp;
        }
        // Odd steps act as padding—no computation, just control flow overhead
    }
}
