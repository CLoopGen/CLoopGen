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
    // Variant 1: Consecutive memory access by unrolling and reordering to access color elements consecutively
    uint8_t *b = buf + start * linesize;
    for (k = start; k < end; k++) {
        b[0] += color[0];
        b[1] += color[1];
        b[2] += color[2];
        b[3] += color[3];
        b += linesize;
    }
}
