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
for (i = 7; i >= 0; i -= 2) {
    uint8_t tmp1 = (r ^ k) & 63;
    uint8_t tmp2 = ((r >> 4) ^ (k >> 6)) & 63;
    out |= S_boxes_P_shuffle[i][tmp1];
    if (i > 0) {
        out |= S_boxes_P_shuffle[i-1][tmp2];
    }
    r = (r >> 8) | (r << 24);
    k >>= 12;
}
}
