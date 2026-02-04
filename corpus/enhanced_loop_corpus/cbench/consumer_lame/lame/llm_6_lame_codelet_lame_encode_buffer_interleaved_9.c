#include <stdio.h>

#include <inttypes.h>

extern short mfbuf[2][3056];
extern int mf_size;
extern short buffer[];
extern int i;
extern int n_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < n_out; ++j) {
        mfbuf[0][mf_size + j] = buffer[2 * j];
    }
    for (j = 0; j < n_out; ++j) {
        mfbuf[1][mf_size + j] = buffer[2 * j + 1];
    }
}
