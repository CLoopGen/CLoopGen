#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nal_length_size;
extern  uint8_t *buf;
extern int *buf_index;
extern int i;
extern int nalsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive prefetch-style access with manual unrolling simulation
    // Assumes small fixed maximum nal_length_size (e.g., up to 4), common in NAL units
    nalsize = 0;
    int idx = *buf_index;
    // Simulate consecutive byte reads without pointer arithmetic in loop condition
    for (i = 0; i < nal_length_size && i < 4; i++) {
        nalsize = (nalsize << 8) | buf[idx + i];
    }
    *buf_index = idx + nal_length_size; // Update buffer index after sequential access
}
