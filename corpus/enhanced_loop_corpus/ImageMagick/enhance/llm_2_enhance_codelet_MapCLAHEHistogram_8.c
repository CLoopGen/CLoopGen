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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < (ssize_t)number_bins; i += 2) {
        sum += histogram[i];
        histogram[i] = (size_t)(range_info->min + scale * sum);
        if (histogram[i] > range_info->max)
            histogram[i] = range_info->max;

        // Handle next element if within bounds
        if (i + 1 < (ssize_t)number_bins) {
            sum += histogram[i + 1];
            histogram[i + 1] = (size_t)(range_info->min + scale * sum);
            if (histogram[i + 1] > range_info->max)
                histogram[i + 1] = range_info->max;
        }
    }
}
