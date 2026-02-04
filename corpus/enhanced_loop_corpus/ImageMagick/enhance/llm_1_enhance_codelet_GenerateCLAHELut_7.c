#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _RangeInfo {
    unsigned short min;
    unsigned short max;
} RangeInfo;

extern  RangeInfo *range_info;
extern unsigned short *lut;
extern ssize_t i;
extern unsigned short delta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective loop nesting (already flat), but simulate deeper logic by splitting the iteration space into two sequential loops
    ssize_t mid = ((ssize_t)range_info->min + (ssize_t)range_info->max) / 2;

    for (i = (ssize_t)range_info->min; i <= mid; i++)
        lut[i] = (unsigned short)((i - range_info->min) / delta);

    for (i = mid + 1; i <= (ssize_t)range_info->max; i++)
        lut[i] = (unsigned short)((i - range_info->min) / delta);
}
