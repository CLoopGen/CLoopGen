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
    // Variant 2: Consecutive memory write simulation via temporary accumulation buffer
    // Simulate consecutive access pattern by batching updates to sum and state variables,
    // then applying them in bulk — mimicking coalesced or vectorized access behavior.
    // This variant accumulates changes over multiple iterations before updating global state.

    const int block_size = 4;
    double temp_sum_delta[block_size];
    double temp_rk_vals[block_size];
    double temp_xk_vals[block_size];

    int full_blocks = nexp / block_size;
    int remainder = nexp % block_size;

    for (int block = 0; block < full_blocks; block++) {
        // Precompute values for this block (simulating consecutive data layout)
        for (int j = 0; j < block_size; j++) {
            int iter_index = nexp - (block * block_size + j);
            temp_xk_vals[j] = xk - (iter_index - 1) * x; // predicted xk at this iteration
            temp_rk_vals[j] = rk - (iter_index - 1);
            double xk_inv = 1. / temp_xk_vals[j];
            temp_sum_delta[j] = ((((((720. * xk_inv + 720.) * xk_inv + 360.) * xk_inv + 120.) * xk_inv + 30.) * xk_inv + 6.) * xk_inv + 1.) / temp_rk_vals[j];
        }

        // Apply transformations in forward order to simulate vector load/store
        double local_sum = sum;
        for (int j = 0; j < block_size; j++) {
            local_sum *= ex;
            local_sum += temp_sum_delta[j];
        }
        sum = local_sum;

        // Update shared state after block
        rk -= block_size;
        xk -= block_size * x;
    }

    // Handle remaining iterations normally (consecutive scalar fallback)
    for (i = remainder; i >= 1; i--) {
        double xk_inv = 1. / xk;
        sum *= ex;
        sum += ((((((720. * xk_inv + 720.) * xk_inv + 360.) * xk_inv + 120.) * xk_inv + 30.) * xk_inv + 6.) * xk_inv + 1.) / rk;
        rk -= 1.;
        xk -= x;
    }
}
