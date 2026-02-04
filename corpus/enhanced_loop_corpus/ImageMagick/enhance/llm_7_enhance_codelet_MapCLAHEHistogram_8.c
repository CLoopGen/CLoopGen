#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _RangeInfo {
    unsigned short min;
    unsigned short max;
} RangeInfo;

extern  RangeInfo *range_info;
extern  size_t number_bins;
extern size_t *histogram;
extern double scale;
extern double sum;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_sum = sum;
    for (i = 0; i < (ssize_t)number_bins; i++) {
        size_t prev_hist = (i > 0) ? histogram[i - 1] : 0;
        local_sum += prev_hist; // Introduce WAR: read before write on histogram
        size_t new_val = (size_t)(range_info->min + scale * local_sum);
        if (new_val > range_info->max)
            new_val = range_info->max;
        histogram[i] = new_val;
    }
    sum = local_sum + histogram[number_bins - 1]; // Final update to sum outside loop
}
