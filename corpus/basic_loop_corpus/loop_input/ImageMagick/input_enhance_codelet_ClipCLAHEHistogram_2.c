#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double clip_limit;
size_t number_bins;
size_t *histogram;
ssize_t cumulative_excess;
ssize_t i;

void init_vars() {
    clip_limit = 100.0;
    number_bins = (1 << 24) / sizeof(size_t);  // ~16.7M elements, leading to ~128MB of data
    histogram = (size_t*)aligned_alloc(64, number_bins * sizeof(size_t));
    if (!histogram) {
        exit(1);
    }
    for (size_t idx = 0; idx < number_bins; idx++) {
        histogram[idx] = 90 + (idx % 25);  // Values around 90-114, some above clip_limit
    }
    cumulative_excess = 0;
    i = 0;
}