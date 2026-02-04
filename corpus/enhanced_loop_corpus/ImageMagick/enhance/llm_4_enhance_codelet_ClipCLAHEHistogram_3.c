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
    ssize_t hist_val = (ssize_t)histogram[i];
    if ((double)hist_val <= clip_limit && hist_val <= excess) {
        cumulative_excess -= step;
        histogram[i] += (size_t)step;
    } else {
        if (hist_val > excess) {
            cumulative_excess -= hist_val - excess;
        }
        histogram[i] = (size_t)clip_limit;
    }
}
}
