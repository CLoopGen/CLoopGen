#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled loop (partial)
    // Unroll by factor of 4 to increase operation count per iteration, reducing trip count
    for (i = 0; i < 20; i += 4) {
        total_hist_br_prob[i]     += hist_br_prob[i] * 2 + 1;
        total_hist_br_prob[i + 1] += hist_br_prob[i + 1] * 2 + 1;
        total_hist_br_prob[i + 2] += hist_br_prob[i + 2] * 2 + 1;
        total_hist_br_prob[i + 3] += hist_br_prob[i + 3] * 2 + 1;
    }
}
