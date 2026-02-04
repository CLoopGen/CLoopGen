#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (accessing every second element)
    // We adjust the loop bound accordingly and handle wrap-around using modulo to stay within bounds
    for (i = 0; i < 4; i++) {
        int idx = (i * 2) % 8;           // Strided access: 0, 2, 4, 6
        int mirror_idx = (7 - idx);      // Mirror index in the array
        src[idx] = ((src[idx] << 16) | (src[idx] >> 16)) ^ src[mirror_idx];
    }
}
