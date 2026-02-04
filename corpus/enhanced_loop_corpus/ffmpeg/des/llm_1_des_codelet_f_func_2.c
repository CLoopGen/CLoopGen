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
for (i = 7; i >= 0; i -= 2) {  // Decreased effective depth by increasing step and using two iterations per loop
    uint8_t tmp1 = (r ^ k) & 63;
    out |= S_boxes_P_shuffle[i][tmp1];
    r = (r >> 4) | (r << 28);
    k >>= 6;

    if (i - 1 >= 0) {
        uint8_t tmp2 = (r ^ k) & 63;
        out |= S_boxes_P_shuffle[i-1][tmp2];
        r = (r >> 4) | (r << 28);
        k >>= 6;
    }
}
}
