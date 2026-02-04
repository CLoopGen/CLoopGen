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
    ssize_t n = (ssize_t)(range_info->max - range_info->min) + 1;
    for (i = 0; i < n; i++) {
        lut[range_info->min + i] = (unsigned short)(i / delta);
    }
}
