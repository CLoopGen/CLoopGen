#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int i;
extern int stride;
extern int map;
extern int hi;
extern int lo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t values[16]; // Precompute output values in a local array
    int idx = 0;
    int temp_map = map;
    
    // Precompute all 16 possible byte values based on bit patterns
    for (int j = 0; j < 4; j++) {
        values[idx++] = (temp_map & 1) ? hi : lo;
        values[idx++] = (temp_map & 2) ? hi : lo;
        values[idx++] = (temp_map & 4) ? hi : lo;
        values[idx++] = (temp_map & 8) ? hi : lo;
        temp_map >>= 4;
    }

    // Strided write using precomputed data: each output element is written with fixed offset
    uint8_t *local_out = out;
    for (i = 0; i < 4; i++) {
        out[0*stride] = values[i*4 + 0];
        out[1*stride] = values[i*4 + 1];
        out[2*stride] = values[i*4 + 2];
        out[3*stride] = values[i*4 + 3];
        out += 1; // Move base pointer by 1 byte each iteration (transposed access)
    }
}
