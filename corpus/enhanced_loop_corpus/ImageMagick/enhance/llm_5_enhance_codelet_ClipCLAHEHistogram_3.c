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
for (i = 0; i < (ssize_t)number_bins; i++) {
    double hist_d = (double)histogram[i];
    ssize_t clipped_or_not = (hist_d > clip_limit);
    ssize_t above_excess = ((ssize_t)histogram[i] > excess);

    if (clipped_or_not || above_excess) {
        if (above_excess) {
            cumulative_excess -= (ssize_t)histogram[i] - excess;
        }
        histogram[i] = (size_t)clip_limit;
    } else {
        cumulative_excess -= step;
        histogram[i] += (size_t)step;
    }
}
}
