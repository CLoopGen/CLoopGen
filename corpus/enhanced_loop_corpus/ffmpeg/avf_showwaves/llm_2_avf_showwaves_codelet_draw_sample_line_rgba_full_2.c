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
    // Variant 1: Consecutive memory access by unrolling and writing 4 bytes at once using a temporary array
    uint8_t temp[4];
    for (k = start; k < end; k++) {
        temp[0] = color[0];
        temp[1] = color[1];
        temp[2] = color[2];
        temp[3] = color[3];
        buf[k * linesize + 0] = temp[0];
        buf[k * linesize + 1] = temp[1];
        buf[k * linesize + 2] = temp[2];
        buf[k * linesize + 3] = temp[3];
    }
}
