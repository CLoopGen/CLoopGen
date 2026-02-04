#include <stdio.h>

#include <inttypes.h>

extern short mfbuf[2][3056];
extern int mf_size;
extern short buffer[];
extern int i;
extern int n_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order
    // Access buffer with negative stride by reversing iteration and computing indices accordingly
    // This changes spatial locality and access pattern
    for (i = n_out - 1; i >= 0; --i) {
        int idx = 2 * i;
        mfbuf[0][mf_size + i] = buffer[idx];
        mfbuf[1][mf_size + i] = buffer[idx + 1];
    }
}
