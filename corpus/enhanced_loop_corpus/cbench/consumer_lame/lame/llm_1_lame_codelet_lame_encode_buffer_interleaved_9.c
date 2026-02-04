#include <stdio.h>

#include <inttypes.h>

extern short mfbuf[2][3056];
extern int mf_size;
extern short buffer[];
extern int i;
extern int n_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    int chunk_size = 16;
    for (outer_i = 0; outer_i < n_out; outer_i += chunk_size) {
        for (inner_i = outer_i; inner_i < outer_i + chunk_size && inner_i < n_out; ++inner_i) {
            i = inner_i;
            mfbuf[0][mf_size + i] = buffer[2 * i];
            mfbuf[1][mf_size + i] = buffer[2 * i + 1];
        }
    }
}
