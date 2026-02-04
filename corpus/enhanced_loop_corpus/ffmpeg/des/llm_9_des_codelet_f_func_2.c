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
for (i = 0; i < 16; i++) {
    uint8_t tmp = (r ^ (k >> (i % 6))) & 63;
    out ^= S_boxes_P_shuffle[i % 8][tmp] + (r & 0xFF);
    r = (r >> 2) | (r << 30);
    k = (k >> 3) | (k << 61);
}
}
