#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern  int nexp;
extern  double ex;
extern double sum;
extern double xk;
extern double rk;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive access pattern via unrolled accumulation (simulated vector-like access)
    // Unroll the loop by a factor of 2 to enable consecutive operations and expose memory-level parallelism
    double temp_sum1 = 0.0, temp_sum2 = 0.0;
    double current_rk = rk;
    double current_xk = xk;
    double temp_x = x;
    int start = nexp;

    // Process two iterations per loop body with forward indexing (consecutive logical access)
    for (i = 0; i < start / 2; i++) {
        // First "half" update (simulates backward index: nexp - i*2)
        temp_sum1 *= ex;
        temp_sum1 += (1. + 1. / current_xk) / current_rk;
        current_rk -= 1.0;
        current_xk -= temp_x;

        // Second "half"
        temp_sum1 *= ex;
        temp_sum1 += (1. + 1. / current_xk) / current_rk;
        current_rk -= 1.0;
        current_xk -= temp_x;
    }

    // Handle leftover iteration if nexp is odd
    if (start % 2 == 1) {
        temp_sum2 *= ex;
        temp_sum2 += (1. + 1. / current_xk) / current_rk;
        sum += temp_sum1 + temp_sum2;
    } else {
        sum += temp_sum1;
    }

    // Update state variables
    rk = current_rk;
    xk = current_xk;
}
