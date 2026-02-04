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
    uint32_t temp_out = 0;
    uint32_t r_local = r;
    uint64_t k_local = k;
    for (i = 7; i >= 0; i--) {
        uint8_t tmp = (r_local ^ k_local) & 63;
        temp_out ^= S_boxes_P_shuffle[i][tmp];  // Change: Use XOR instead of OR to remove WAW dependency on 'out'
        r_local = (r_local >> 4) | (r_local << 28);
        k_local >>= 6;
    }
    out = temp_out;  // Single write to 'out' after loop — eliminates loop-carried WAW on 'out'
}
