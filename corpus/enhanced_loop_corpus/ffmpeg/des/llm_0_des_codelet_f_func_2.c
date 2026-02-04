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
for (i = 7; i >= 0; i--) {
    for (int j = 0; j < 1; j++) {  // Increased nesting depth: added inner trivial loop
        uint8_t tmp = (r ^ k) & 63;
        out |= S_boxes_P_shuffle[i][tmp];
        r = (r >> 4) | (r << 28);
        k >>= 6;
    }
}
}
