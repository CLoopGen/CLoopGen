#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

double clip_limit;
size_t number_bins;
size_t *histogram;
ssize_t cumulative_excess;
ssize_t excess;
ssize_t i;
ssize_t step;

void init_vars() {
    // Set parameters to create approximately 100MB of data
    number_bins = 25000000;  // 25 million bins
    clip_limit = 100.0;
    excess = 80;
    cumulative_excess = 5000000;
    step = 2;

    // Allocate histogram array
    histogram = (size_t*)aligned_alloc(64, number_bins * sizeof(size_t));
    
    // Initialize histogram with sample values within expected range
    for (size_t idx = 0; idx < number_bins; idx++) {
        // Random-like initialization between 70 and 90 to trigger various branches
        histogram[idx] = 70 + (idx % 21);
    }
}

// Provide weak definition of loop if needed for standalone linking,
// but assume it will be provided externally as per requirements.
// This ensures linkage when building.
__attribute__((weak)) void loop();

void loop() {
    for (i = 0; i < (ssize_t)number_bins; i++) {
        if ((double)histogram[i] > clip_limit)
            histogram[i] = (size_t)clip_limit;
        else if ((ssize_t)histogram[i] > excess) {
            cumulative_excess -= (ssize_t)histogram[i] - excess;
            histogram[i] = (size_t)clip_limit;
        } else {
            cumulative_excess -= step;
            histogram[i] += (size_t)step;
        }
    }
}