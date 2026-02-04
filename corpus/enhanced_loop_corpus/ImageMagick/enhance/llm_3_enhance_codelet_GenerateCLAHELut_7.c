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
    // Variant 2: Reverse consecutive memory access
    // Traverse from max to min consecutively, writing in reverse order
    ssize_t start = (ssize_t)range_info->min;
    ssize_t end = (ssize_t)range_info->max;
    for (i = end; i >= start; i--) {
        lut[i] = (unsigned short)((i - start) / delta);
    }
}
