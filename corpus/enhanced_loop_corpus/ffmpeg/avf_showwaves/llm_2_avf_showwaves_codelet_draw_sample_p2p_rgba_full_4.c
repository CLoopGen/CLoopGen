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
    // Variant 1: Consecutive memory access by unrolling and writing 4 elements at a time consecutively
    uint8_t *base = &buf[(start + 1) * linesize];
    int stride = linesize - 4;
    for (k = start + 1; k < end; k++) {
        base[0] = color[0];
        base[1] = color[1];
        base[2] = color[2];
        base[3] = color[3];
        base += linesize; // Move to next row with stride
    }
}
