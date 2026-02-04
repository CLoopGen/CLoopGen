#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int num_levels = 128;
int freq[256];
int q_level[256];
double inv_q_level[256];
int min_s = 0;
int max_s = 255;
int iter;
double last_err = 1e10;
double err;
double err_threshold = 1e-6;

void init_vars() {
    // Initialize freq with non-zero values for all s in [min_s, max_s]
    for (int i = 0; i < 256; ++i) {
        freq[i] = (i >= min_s && i <= max_s) ? (rand() % 100 + 1) : 0;
    }

    // Initialize q_level to a valid slot index within [0, num_levels-1]
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            q_level[i] = (i * num_levels / 256) % num_levels;
        } else {
            q_level[i] = 0;
        }
    }

    // Initialize inv_q_level such that it is increasing and avoids edge conditions
    for (int i = 0; i < num_levels; ++i) {
        inv_q_level[i] = (double)(min_s + (max_s - min_s) * i / (num_levels - 1));
    }

    // Ensure boundaries are safe
    if (num_levels <= 1) {
        num_levels = 2;
    }

    // Clamp min_s and max_s to valid range
    if (min_s < 0) min_s = 0;
    if (max_s > 255) max_s = 255;
    if (min_s > max_s) max_s = min_s;

    // Re-initialize inv_q_level with spread-out values to prevent division by zero or NaN
    for (int i = 0; i < num_levels; ++i) {
        inv_q_level[i] = min_s + (double)(max_s - min_s) * i / (num_levels - 1 + 1e-9);
    }

    // Initialize err to a large value so loop runs at least once
    err = 1e9;

    // Initialize iter to zero (will be overwritten in loop, but safe)
    iter = 0;
}