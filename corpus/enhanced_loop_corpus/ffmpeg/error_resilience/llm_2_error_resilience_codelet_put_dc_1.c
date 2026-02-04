#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest_cb;
extern uint8_t *dest_cr;
extern int *linesize;
extern int dcu;
extern int dcv;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Linear Indexing and Prefetching Pattern
    int idx = 0;
    for (int y = 0; y < 8; y++) {
        int base_cb = y * linesize[1];
        int base_cr = y * linesize[2];
        for (int x = 0; x < 8; x++) {
            int offset_cb = base_cb + x;
            int offset_cr = base_cr + x;
            dest_cb[offset_cb] = dcu / 8;
            dest_cr[offset_cr] = dcv / 8;
        }
    }
}
