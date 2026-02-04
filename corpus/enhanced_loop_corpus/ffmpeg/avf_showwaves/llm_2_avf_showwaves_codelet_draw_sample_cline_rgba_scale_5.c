#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern  int start;
extern  int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reordering to access memory sequentially across iterations
    int offset;
    uint8_t c0 = color[0], c1 = color[1], c2 = color[2], c3 = color[3];
    for (k = start; k < end; k++) {
        offset = k * linesize;
        buf[offset + 0] += c0;
        buf[offset + 1] += c1;
        buf[offset + 2] += c2;
        buf[offset + 3] += c3;
    }
}
