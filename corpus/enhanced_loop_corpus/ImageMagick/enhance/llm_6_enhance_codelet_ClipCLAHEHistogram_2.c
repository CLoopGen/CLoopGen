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
    ssize_t temp_excess = 0;
    for (i = 0; i < (ssize_t)number_bins; i++) {
        if (histogram[i] > clip_limit)
            temp_excess += (ssize_t)(histogram[i] - clip_limit);
    }
    cumulative_excess += temp_excess;
}
