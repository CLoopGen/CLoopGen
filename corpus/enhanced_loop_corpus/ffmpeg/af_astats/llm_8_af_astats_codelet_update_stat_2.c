#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ChannelStats {
    double last;
    double last_non_zero;
    double min_non_zero;
    double sigma_x;
    double sigma_x2;
    double avg_sigma_x2;
    double min_sigma_x2;
    double max_sigma_x2;
    double min;
    double max;
    double nmin;
    double nmax;
    double min_run;
    double max_run;
    double min_runs;
    double max_runs;
    double min_diff;
    double max_diff;
    double diff1_sum;
    double diff1_sum_x2;
    uint64_t mask;
    uint64_t imask;
    uint64_t min_count;
    uint64_t max_count;
    uint64_t noise_floor_count;
    uint64_t zero_runs;
    uint64_t nb_samples;
    uint64_t nb_nans;
    uint64_t nb_infs;
    uint64_t nb_denormals;
    double *win_samples;
    unsigned int histogram[8192];
    int win_pos;
    int max_index;
    double noise_floor;
} ChannelStats;

extern ChannelStats *p;
extern double noise_floor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled trip count
    double inv_denom = 1.0 / (8192.0 - 1.0);
    int i = p->max_index;
    for (; i >= 0; i -= 2) {
        if (i < 8192 && p->histogram[i]) {
            noise_floor = i * inv_denom;
            break;
        }
        if (i-1 >= 0 && i-1 < 8192 && p->histogram[i-1]) {
            noise_floor = (i-1) * inv_denom;
            break;
        }
    }
    // Handle odd boundary if loop did not catch the last element
    if (i <= 0 && !p->histogram[i]) {
        for (int j = 0; j <= p->max_index; j++) {
            if (p->histogram[j]) {
                noise_floor = j * inv_denom;
                break;
            }
        }
    }
}
