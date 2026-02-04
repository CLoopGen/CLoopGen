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
    for (i = 0; i < (ssize_t)number_bins; i += 2) {
        sum += histogram[i];
        if (i + 1 < (ssize_t)number_bins) {
            sum += histogram[i + 1];
        }
        size_t val1 = (size_t)(range_info->min + scale * sum);
        histogram[i] = (val1 > range_info->max) ? range_info->max : val1;
        if (i + 1 < (ssize_t)number_bins) {
            size_t val2 = (size_t)(range_info->min + scale * sum);
            histogram[i + 1] = (val2 > range_info->max) ? range_info->max : val2;
        }
    }
}
