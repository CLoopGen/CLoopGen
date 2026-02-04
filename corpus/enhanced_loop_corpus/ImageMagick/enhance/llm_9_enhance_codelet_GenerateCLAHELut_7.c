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
    ssize_t base = (ssize_t)range_info->min;
    ssize_t limit = (ssize_t)range_info->max;
    for (i = base; i <= limit; i++) {
        unsigned short diff = (unsigned short)(i - base);
        unsigned short quotient = diff / delta;
        unsigned short remainder = diff % delta;
        lut[i] = (unsigned short)(quotient + (remainder > 0 ? 1 : 0));
    }
}
