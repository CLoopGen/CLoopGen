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
    // Variant 1: Consecutive memory access with reverse traversal unrolled by 2
    int i = p->max_index;
    // Unroll by 2 for consecutive backward access
    for (; i >= 1; i -= 2) {
        if (p->histogram[i]) {
            noise_floor = i / (double)(8192 - 1);
            return;
        }
        if (p->histogram[i-1]) {
            noise_floor = (i - 1) / (double)(8192 - 1);
            return;
        }
    }
    // Handle remaining element
    if (i == 0 && p->histogram[0]) {
        noise_floor = 0.0;
    }
}
