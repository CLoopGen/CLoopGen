#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t value;
extern int32_t factor;
extern  int32_t *intervals;
extern int32_t nb_intervals;
extern int32_t idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t threshold = ((int64_t)value << 24);
    int64_t inv_factor = (factor != 0) ? ((1LL << 32) / (int64_t)factor) : 0; // Precompute reciprocal for division-like behavior
    int32_t step = nb_intervals >> 1;

    // Unroll the first iteration to increase arithmetic intensity
    if (step > 0 && ((int64_t)(intervals[idx + step])) <= threshold * inv_factor >> 8)
    {
        idx += step;
        step >>= 1;
    }

    // Continue with reduced iterations but enhanced computation per iteration
    for (i = step; i > 0; i >>= 1) {
        int64_t interval_val = (int64_t)intervals[idx + i];
        int64_t product = interval_val * (int64_t)factor;

        // Introduce redundant but optimizing-friendly comparison using bit manipulation
        int64_t diff = threshold - product;
        int32_t update = -(diff >= 0); // becomes -1 if true, 0 otherwise
        idx += (i & update); // conditional add without branching (if supported)
    }
}
