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
    unsigned short base = 0;
    for (i = start; i <= end; i++) {
        ssize_t idx = i - start;
        lut[i] = base + (unsigned short)(idx / delta);
    }
}
