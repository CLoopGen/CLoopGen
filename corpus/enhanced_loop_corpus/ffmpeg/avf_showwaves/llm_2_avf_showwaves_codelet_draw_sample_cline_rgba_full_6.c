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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *ptr = &buf[start * linesize];
    uint8_t c0 = color[0], c1 = color[1], c2 = color[2], c3 = color[3];
    int step = linesize;
    for (k = start; k < end; k++) {
        ptr[0] = c0;
        ptr[1] = c1;
        ptr[2] = c2;
        ptr[3] = c3;
        ptr += step;
    }
}
