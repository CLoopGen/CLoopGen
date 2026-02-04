#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double x;
extern double sum;
extern double term;
extern int n;
extern int nlow;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern (simulated with step size > 1)
    // Here we simulate a strided iteration by increasing n in steps of 2, 
    // effectively skipping every other element in the logical sequence.
    for (n = 1; n < nlow; n += 2) {
        double temp_x = x;
        double temp_a = a + n;
        term *= temp_x / temp_a;
        sum += term;

        // Process intermediate n+1 if within bounds (to maintain correctness approximation)
        if (n + 1 < nlow) {
            temp_a = a + (n + 1);
            term *= temp_x / temp_a;
            sum += term;
        }
    }
}
