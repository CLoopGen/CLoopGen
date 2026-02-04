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
    // Variant 1: Increased computational intensity by unrolling the loop and increasing effective trip count
    // Each iteration now handles two rows instead of one, doubling memory operations per iteration
    int k;
    for (k = start; k < end - 1; k += 2) {
        int offset1 = k * linesize;
        int offset2 = (k + 1) * linesize;
        buf[offset1 + 0] = color[0];
        buf[offset1 + 1] = color[1];
        buf[offset1 + 2] = color[2];
        buf[offset1 + 3] = color[3];
        buf[offset2 + 0] = color[0];
        buf[offset2 + 1] = color[1];
        buf[offset2 + 2] = color[2];
        buf[offset2 + 3] = color[3];
    }
    // Handle remaining iteration if end - start is odd
    if (k == end - 1) {
        int offset = k * linesize;
        buf[offset + 0] = color[0];
        buf[offset + 1] = color[1];
        buf[offset + 2] = color[2];
        buf[offset + 3] = color[3];
    }
}
