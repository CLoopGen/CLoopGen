#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

typedef unsigned char U8;

typedef int I32;

extern STRLEN tlen;
extern U8 *t;
extern I32 i;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Processes every second element in forward direction, then loops back for odd indices if needed
    I32 stride = 2;
    STRLEN limit = tlen;

    for (i = 0; i < (I32)limit; i += stride)
        tbl[t[i]] = -1;

    for (i = 1; i < (I32)limit && stride > 1; i += stride)
        tbl[t[i]] = -1;
}
