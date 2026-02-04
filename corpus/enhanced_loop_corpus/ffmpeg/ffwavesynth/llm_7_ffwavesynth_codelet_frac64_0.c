#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t b;
extern uint64_t r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_r = r;
    uint64_t local_a = a;
    uint64_t precomputed[64];
    // Precompute shift values to remove loop-carried dependency on shifting
    for (int j = 0; j < 64; j++) {
        precomputed[j] = (uint64_t)1 << j;
    }
    for (i = 63; i >= 0; i--) {
        uint64_t double_a = local_a << 1;
        uint64_t mask = precomputed[i]; // Use precomputed value to eliminate shift dependency
        if (local_a >= ((uint64_t)1 << 63) || double_a >= b) {
            local_r |= mask;
            local_a = double_a - b;
        } else {
            local_a = double_a;
        }
    }
    r = local_r; // Single write-back at semantic end
    a = local_a;
}
