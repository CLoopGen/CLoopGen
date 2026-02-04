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
for (i = 0; i < (ssize_t)number_bins; i++) {
    sum += histogram[i];
    double scaled_val = scale * sum;
    if (scaled_val < 0.0) continue;
    size_t new_val = (size_t)(range_info->min + scaled_val);
    if (new_val >= range_info->min && new_val <= range_info->max) {
        histogram[i] = new_val;
    } else if (new_val > range_info->max) {
        histogram[i] = range_info->max;
    } else {
        histogram[i] = range_info->min;
    }
}
}
