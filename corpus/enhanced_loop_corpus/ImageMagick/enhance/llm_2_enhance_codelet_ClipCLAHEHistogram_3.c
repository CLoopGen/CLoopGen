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
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    ssize_t n = (ssize_t)number_bins;
    for (i = 0; i < n; i += 2) {
        if (i < n && (double)histogram[i] > clip_limit)
            histogram[i] = (size_t)clip_limit;
        else if (i < n && (ssize_t)histogram[i] > excess) {
            cumulative_excess -= (ssize_t)histogram[i] - excess;
            histogram[i] = (size_t)clip_limit;
        } else if (i < n) {
            cumulative_excess -= step;
            histogram[i] += (size_t)step;
        }
    }
    for (i = 1; i < n; i += 2) {
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
