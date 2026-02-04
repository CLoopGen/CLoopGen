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
    // Variant 1: Consecutive memory access with unrolling (accessing multiple elements per iteration)
    int i;
    for (i = start; i < end; i += 4) {
        int idx0 = i * linesize;
        int idx1 = (i + 1) * linesize;
        int idx2 = (i + 2) * linesize;
        int idx3 = (i + 3) * linesize;
        if (i < end)         buf[idx0] += color[0];
        if (i + 1 < end)     buf[idx1] += color[0];
        if (i + 2 < end)     buf[idx2] += color[0];
        if (i + 3 < end)     buf[idx3] += color[0];
    }
}
