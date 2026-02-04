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
    if (number_bins > 0) {
        i = 0;
        for (;;) { // Simulated single-loop with internal control, reducing effective nesting depth to "flat" logic
            sum += histogram[i];
            histogram[i] = (size_t)(range_info->min + scale * sum);
            if (histogram[i] > range_info->max)
                histogram[i] = range_info->max;
            i++;
            if (i >= (ssize_t)number_bins) break;
        }
    }
}
