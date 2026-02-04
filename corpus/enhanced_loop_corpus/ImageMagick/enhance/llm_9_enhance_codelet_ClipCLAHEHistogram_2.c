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
    ssize_t local_excess = 0;
    size_t unroll_factor = 4;
    size_t rounded_down = ((number_bins / unroll_factor) * unroll_factor);

    for (i = 0; i < (ssize_t)rounded_down; i += unroll_factor) {
        double diff;
        diff = histogram[i] - clip_limit;
        if (diff > 0) local_excess += (ssize_t)diff;
        
        diff = histogram[i + 1] - clip_limit;
        if (diff > 0) local_excess += (ssize_t)diff;
        
        diff = histogram[i + 2] - clip_limit;
        if (diff > 0) local_excess += (ssize_t)diff;
        
        diff = histogram[i + 3] - clip_limit;
        if (diff > 0) local_excess += (ssize_t)diff;
    }

    for (; i < (ssize_t)number_bins; i++) {
        if (histogram[i] > clip_limit)
            local_excess += (ssize_t)(histogram[i] - clip_limit);
    }

    cumulative_excess += local_excess;
}
