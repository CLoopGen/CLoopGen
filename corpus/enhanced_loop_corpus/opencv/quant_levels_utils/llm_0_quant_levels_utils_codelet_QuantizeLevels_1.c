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
    int s, slot;
    for (s = min_s; s <= max_s; ++s) {
        for (slot = 0; slot < num_levels - 1; ++slot) {
            if (2 * s <= inv_q_level[slot] + inv_q_level[slot + 1]) break;
        }
        if (freq[s] > 0) {
            q_sum[slot] += s * freq[s];
            q_count[slot] += freq[s];
        }
        q_level[s] = slot;
    }
    if (num_levels > 2) {
        for (slot = 1; slot < num_levels - 1; ++slot) {
            const double count = q_count[slot];
            if (count > 0.) {
                inv_q_level[slot] = q_sum[slot] / count;
            }
        }
    }
    err = 0.;
    for (s = min_s; s <= max_s; ++s) {
        const double error = s - inv_q_level[q_level[s]];
        err += freq[s] * error * error;
    }
    if (last_err - err < err_threshold)
        break;
    last_err = err;
}
}
