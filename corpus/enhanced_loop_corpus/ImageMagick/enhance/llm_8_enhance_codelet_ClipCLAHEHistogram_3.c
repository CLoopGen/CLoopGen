#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double clip_limit;
extern  size_t number_bins;
extern size_t *histogram;
extern ssize_t cumulative_excess;
extern ssize_t excess;
extern ssize_t i;
extern ssize_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t limit = (ssize_t)clip_limit;
    for (i = 0; i < (ssize_t)number_bins; i += 2) {
        if (i + 1 < (ssize_t)number_bins) {
            // Process two elements per iteration to reduce trip count and increase computational intensity
            if ((double)histogram[i] > clip_limit) {
                histogram[i] = (size_t)limit;
            } else if ((ssize_t)histogram[i] > excess) {
                cumulative_excess -= (ssize_t)histogram[i] - excess;
                histogram[i] = (size_t)limit;
            } else {
                cumulative_excess -= step;
                histogram[i] += (size_t)step;
            }

            if ((double)histogram[i+1] > clip_limit) {
                histogram[i+1] = (size_t)limit;
            } else if ((ssize_t)histogram[i+1] > excess) {
                cumulative_excess -= (ssize_t)histogram[i+1] - excess;
                histogram[i+1] = (size_t)limit;
            } else {
                cumulative_excess -= step;
                histogram[i+1] += (size_t)step;
            }
        } else {
            // Handle last element if number_bins is odd
            if ((double)histogram[i] > clip_limit) {
                histogram[i] = (size_t)limit;
            } else if ((ssize_t)histogram[i] > excess) {
                cumulative_excess -= (ssize_t)histogram[i] - excess;
                histogram[i] = (size_t)limit;
            } else {
                cumulative_excess -= step;
                histogram[i] += (size_t)step;
            }
        }
    }
}
