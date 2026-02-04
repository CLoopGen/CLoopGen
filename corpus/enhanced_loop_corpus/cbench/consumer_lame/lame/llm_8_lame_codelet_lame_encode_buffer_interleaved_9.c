#include <stdio.h>

#include <inttypes.h>

extern short mfbuf[2][3056];
extern int mf_size;
extern short buffer[];
extern int i;
extern int n_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_out; i += 2) {
        if (i + 1 < n_out) {
            mfbuf[0][mf_size + i] = buffer[2 * i];
            mfbuf[1][mf_size + i] = buffer[2 * i + 1];
            mfbuf[0][mf_size + i + 1] = buffer[2 * (i + 1)];
            mfbuf[1][mf_size + i + 1] = buffer[2 * (i + 1) + 1];
        } else {
            mfbuf[0][mf_size + i] = buffer[2 * i];
            mfbuf[1][mf_size + i] = buffer[2 * i + 1];
        }
    }
}
