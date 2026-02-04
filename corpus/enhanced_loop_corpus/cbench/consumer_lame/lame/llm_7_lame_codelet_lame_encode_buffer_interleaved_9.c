#include <stdio.h>

#include <inttypes.h>

extern short mfbuf[2][3056];
extern int mf_size;
extern short buffer[];
extern int i;
extern int n_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_val0, temp_val1;
    for (i = 0; i < n_out; ++i) {
        temp_val0 = buffer[2 * i];
        temp_val1 = buffer[2 * i + 1];
        mfbuf[0][mf_size + i] = temp_val0;
        mfbuf[1][mf_size + i] = temp_val1;
    }
}
