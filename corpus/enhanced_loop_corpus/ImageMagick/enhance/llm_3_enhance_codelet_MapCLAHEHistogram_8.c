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
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    for (i = (ssize_t)number_bins - 1; i >= 0; i--) {
        sum += histogram[i];
        histogram[i] = (size_t)(range_info->min + scale * sum);
        if (histogram[i] > range_info->max)
            histogram[i] = range_info->max;
    }
}
