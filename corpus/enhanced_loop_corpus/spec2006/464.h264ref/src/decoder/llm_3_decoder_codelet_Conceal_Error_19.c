#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Arrays
    // Precompute indices using indirect addressing to simulate irregular but deterministic access
    int indices[256];
    int idx = 0;
    for (int j_idx = 0; j_idx < 16; j_idx++) {
        for (int i_idx = 0; i_idx < 16; i_idx++) {
            indices[idx++] = (j_idx << 4) | i_idx;  // Store combined index
        }
    }
    // Now traverse using indirect indexing
    for (int k = 0; k < 256; k++) {
        int j_idx = indices[k] >> 4;
        int i_idx = indices[k] & 0xF;
        inY[pos_y + j_idx][pos_x + i_idx] = 127;
    }
}
