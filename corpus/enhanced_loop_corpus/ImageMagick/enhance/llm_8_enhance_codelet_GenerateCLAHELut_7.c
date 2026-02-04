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
    ssize_t start = (ssize_t)range_info->min;
    ssize_t end = (ssize_t)range_info->max;
    ssize_t range = end - start + 1;
    for (i = 0; i < range; i += 2) {
        lut[start + i] = (unsigned short)(i / delta);
        if (start + i + 1 <= end) {
            lut[start + i + 1] = (unsigned short)((i + 1) / delta);
        }
    }
}
