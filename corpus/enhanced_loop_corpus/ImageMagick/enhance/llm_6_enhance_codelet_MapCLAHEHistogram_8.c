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
    ssize_t temp_sum = 0;
    for (i = 0; i < (ssize_t)number_bins; i++) {
        temp_sum += histogram[i];
        size_t scaled_val = (size_t)(range_info->min + scale * temp_sum);
        if (scaled_val > range_info->max)
            scaled_val = range_info->max;
        histogram[i] = scaled_val;
        sum += histogram[i]; // Update global sum after write to break WAW on sum
    }
}
