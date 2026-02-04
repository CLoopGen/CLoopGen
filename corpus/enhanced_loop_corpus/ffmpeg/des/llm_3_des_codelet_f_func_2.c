#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t S_boxes_P_shuffle[8][64];
extern uint32_t r;
extern uint64_t k;
extern int i;
extern uint32_t out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint32_t indices[8];
uint32_t values[8];

for (i = 7; i >= 0; i--) {
    indices[i] = (r ^ k) & 63;
    r = (r >> 4) | (r << 28);
    k >>= 6;
}

for (i = 7; i >= 0; i--) {
    out |= S_boxes_P_shuffle[i][indices[i]];
}
}
