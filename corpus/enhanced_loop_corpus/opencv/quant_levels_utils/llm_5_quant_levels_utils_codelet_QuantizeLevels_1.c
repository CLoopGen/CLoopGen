#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_levels;
extern int freq[256];
extern int q_level[256];
extern double inv_q_level[256];
extern int min_s;
extern int max_s;
extern int iter;
extern double last_err;
extern double err;
extern  double err_threshold;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (iter = 0; iter < 6; ++iter) {
    double q_sum[256] = {0};
    double q_count[256] = {0};
    int s, slot = 0;
    // Control dependency change: Remove the conditional update of q_sum/q_count by fusing condition into arithmetic
    // This eliminates the 'if' by using a flag-as-multiplier technique
    for (s = min_s; s <= max_s; ++s) {
        // Unroll the while logic into a bounded for-check without using while
        for (; slot < num_levels - 1 && 2 * s > inv_q_level[slot] + inv_q_level[slot + 1]; ++slot) {
            // Empty body – advances slot to correct position
        }
        // Eliminate branch on freq[s] > 0 using arithmetic masking
        const double weight = (freq[s] > 0) ? 1.0 : 0.0;
        q_sum[slot] += weight * s * freq[s];
        q_count[slot] += weight * freq[s];
        q_level[s] = slot;
    }
    if (num_levels > 2) {
        for (slot = 1; slot < num_levels - 1; ++slot) {
            // Retain conditional but express as ternary to reduce branching
            inv_q_level[slot] = (q_count[slot] > 0.0) ? (q_sum[slot] / q_count[slot]) : inv_q_level[slot];
        }
    }
    err = 0.;
    for (s = min_s; s <= max_s; ++s) {
        const double error = s - inv_q_level[q_level[s]];
        err += freq[s] * error * error;
    }
    // Convert break condition into unconditional assignment with early exit check at end
    if (last_err - err < err_threshold) {
        last_err = err;
        break;
    }
    last_err = err;
}
}
