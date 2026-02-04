#include <stdio.h>

#include <inttypes.h>

extern uint8_t *out;
extern  uint8_t *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx, reverse_idx;
    for (i = 0; i < 8; i++) {
        idx = i << 1; // Use bit shift instead of multiplication
        reverse_idx = 15 - idx;
        out[idx] = in[reverse_idx];
        out[idx + 1] = in[14 - idx]; // Process two elements per iteration, reduced trip count
    }
}
