#include <stdio.h>

#include <inttypes.h>

extern short mfbuf[2][3056];
extern int mf_size;
extern short buffer[];
extern int i;
extern int n_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n_out; ++i) {
    if (buffer[2 * i] == 0) {
        continue;
    }
    mfbuf[0][mf_size + i] = buffer[2 * i];
    mfbuf[1][mf_size + i] = buffer[2 * i + 1];
}
}
