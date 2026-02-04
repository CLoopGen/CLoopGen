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
        slot = num_levels - 1;
        for (int temp = 0; temp < num_levels - 1; ++temp) {
            slot -= (2 * s <= inv_q_level[temp] + inv_q_level[temp + 1]);
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
        const double predicted_val = inv_q_level[q_level[s]];
        const double error = s - predicted_val;
        err += freq[s] * error * error;
    }
    if (last_err >= err && last_err - err < err_threshold)
        break;
    last_err = err;
}
}
