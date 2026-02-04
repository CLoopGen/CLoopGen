#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double clip_limit;
extern  size_t number_bins;
extern size_t *histogram;
extern ssize_t cumulative_excess;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    for (i = 0; i < (ssize_t)number_bins; i += 2) {
        if (i + 1 < (ssize_t)number_bins) {
            double diff1 = histogram[i] - clip_limit;
            double diff2 = histogram[i + 1] - clip_limit;
            if (diff1 > 0)
                cumulative_excess += (ssize_t)diff1;
            if (diff2 > 0)
                cumulative_excess += (ssize_t)diff2;
        } else {
            double diff = histogram[i] - clip_limit;
            if (diff > 0)
                cumulative_excess += (ssize_t)diff;
        }
    }
}
