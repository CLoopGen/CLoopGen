#include <stdio.h>

#include <inttypes.h>

extern short mfbuf[2][3056];
extern int mf_size;
extern short buffer[];
extern int i;
extern int n_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = n_out >> 1;
    for (i = 0; i < limit; ++i) {
        int idx = 2 * i;
        mfbuf[0][mf_size + idx] = buffer[4 * i];
        mfbuf[1][mf_size + idx] = buffer[4 * i + 1];
        mfbuf[0][mf_size + idx + 1] = buffer[4 * i + 2];
        mfbuf[1][mf_size + idx + 1] = buffer[4 * i + 3];
    }
    if (n_out & 1) {
        int last = n_out - 1;
        mfbuf[0][mf_size + last] = buffer[2 * last];
        mfbuf[1][mf_size + last] = buffer[2 * last + 1];
    }
}
