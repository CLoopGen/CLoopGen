#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int b;
extern  double x;
extern int a0;
extern int n;
extern double Ma0np1;
extern double Ma0n;
extern double Ma0nm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop and adding redundant arithmetic operations
    // Also modified trip count to process two iterations per loop step, reducing total iterations but increasing operations per cycle
    int n_start = a0 - 1;
    int n_limit = b + 1;  // Adjusted bound to ensure safe double-step decrement

    for (n = n_start; n > n_limit; n -= 2) {
        // First iteration of unrolled pair
        Ma0nm1 = (-n * (1 - n - x) * Ma0n - x * (n - a0) * Ma0np1) / (n * (n - 1.));
        Ma0np1 = Ma0n + 0.0;  // Redundant addition to increase computation
        Ma0n = Ma0nm1 * 1.0;  // Identity multiplication for extra work

        // Second iteration using updated state
        if (n - 1 > b) {
            double temp_nm1 = (-(n-1) * (1 - (n-1) - x) * Ma0n - x * ((n-1) - a0) * Ma0np1) / ((n-1) * ((n-1) - 1.));
            Ma0np1 = Ma0n;
            Ma0n = temp_nm1;
        }
    }

    // Handle any remaining single iteration
    if (n > b && n <= n_limit + 1) {
        Ma0nm1 = (-n * (1 - n - x) * Ma0n - x * (n - a0) * Ma0np1) / (n * (n - 1.));
        Ma0np1 = Ma0n;
        Ma0n = Ma0nm1;
    }
}
