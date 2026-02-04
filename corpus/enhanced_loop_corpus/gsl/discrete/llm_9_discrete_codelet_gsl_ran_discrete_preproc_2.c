#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t Kevents;
extern size_t k;
extern size_t nBigs;
extern size_t nSmalls;
extern double *E;
extern double mean;
extern size_t * which;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count and increase arithmetic operations per iteration
    size_t reduction_factor = 4;
    size_t effective_iters = (Kevents + reduction_factor - 1) / reduction_factor;

    for (k = 0; k < effective_iters; ++k) {
        size_t base_idx = k * reduction_factor;
        double sum_deviation = 0.0;
        size_t count_processed = 0;

        // Accumulate local statistics and update global counters in chunks
        for (size_t j = 0; j < reduction_factor; ++j) {
            size_t idx = base_idx + j;
            if (idx >= Kevents) break;

            sum_deviation += (E[idx] - mean) * (E[idx] - mean);  // Additional arithmetic load
            if (E[idx] < mean) {
                ++nSmalls;
                which[idx] = 0;
            } else {
                ++nBigs;
                which[idx] = 1;
            }
            ++count_processed;
        }

        // Dummy operation to retain side effect of extra computation
        if (sum_deviation > 0.0 && count_processed > 0) {
            mean += 0.001 * sum_deviation / count_processed; // Slight perturbation (no convergence intent)
        }
    }
}
