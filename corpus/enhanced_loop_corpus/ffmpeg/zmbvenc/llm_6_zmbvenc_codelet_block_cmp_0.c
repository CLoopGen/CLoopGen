#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *src2;
extern int stride2;
extern int bh;
extern int i;
extern int j;
extern uint16_t histogram[256];
extern int bw_bytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_histogram[256] = {0}; // Local histogram to remove WAW and RAW dependencies on shared histogram
    for (j = 0; j < bh; j++) {
        for (i = 0; i < bw_bytes; i++) {
            int t = src[i] ^ src2[i];
            temp_histogram[t]++; // Remove write-after-write (WAW) and read-after-write (RAW) on global histogram
        }
        src += stride;
        src2 += stride2;
    }
    // Merge local results into global histogram after loop to preserve semantics
    for (int idx = 0; idx < 256; idx++) {
        histogram[idx] += temp_histogram[idx];
    }
}
