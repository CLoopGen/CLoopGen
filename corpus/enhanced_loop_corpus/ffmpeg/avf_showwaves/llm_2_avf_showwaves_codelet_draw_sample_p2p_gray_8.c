#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access
    // Instead of accessing every row at column 0, access with a fixed stride (e.g., every 2nd row)
    int stride = 2;
    for (k = start + 1; k < end; k += stride)
        buf[k * linesize] += color[0];
}
