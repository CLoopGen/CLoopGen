#include <stdio.h>

#include <inttypes.h>

extern short mfbuf[2][3056];
extern int mf_size;
extern short buffer[];
extern int i;
extern int n_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access in buffer (2*i and 2*i+1), we use a single pointer that traverses buffer consecutively
    short *buf_ptr = buffer;
    for (i = 0; i < n_out; ++i) {
        mfbuf[0][mf_size + i] = *buf_ptr++;
        mfbuf[1][mf_size + i] = *buf_ptr++;
    }
}
