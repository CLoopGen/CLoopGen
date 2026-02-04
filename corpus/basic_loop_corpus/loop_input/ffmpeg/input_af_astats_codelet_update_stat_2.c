#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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

ChannelStats *p;
double noise_floor;

void init_vars() {
    // Allocate the ChannelStats structure
    p = (ChannelStats*)calloc(1, sizeof(ChannelStats));
    if (!p) exit(1);

    // Allocate win_samples buffer: ~128MB to ensure loop runs about 0.01s with memory pressure
    size_t win_size = 16 * 1024 * 1024; // 16 million doubles ~ 128 MB
    p->win_samples = (double*)calloc(win_size, sizeof(double));
    if (!p->win_samples) exit(1);

    // Initialize other fields
    p->max_index = 8191; // Must be within [0, 8191] for histogram access

    // Set up histogram so that we have non-zero values only near the end
    // This ensures the loop iterates many times before breaking
    // Simulate realistic distribution: most energy at high indices
    for (int i = 0; i < 8192; i++) {
        p->histogram[i] = 0;
    }
    // Place first non-zero at around index 4000 to make loop run moderately long
    p->histogram[4000] = 1;
    for (int i = 4001; i < 8192; i++) {
        p->histogram[i] = (unsigned int)(rand() % 100);
    }

    // Initialize noise_floor
    noise_floor = 0.0;

    // Other initialization as needed
    p->nb_samples = win_size;
    p->win_pos = 0;
}