#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *top;
extern int top_right_size;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Consecutive 16-bit element access, unroll by 4 to maintain throughput
    // Treat destination as consecutive uint16_t writes instead of packed 64-bit
    uint16_t *dst = top + size + top_right_size;
    for (i = 0; i < (size - top_right_size); i += 4) {
        dst[i + 0] = (uint16_t)(pix & 0xFFFF);
        dst[i + 1] = (uint16_t)((pix >> 16) & 0xFFFF);
        dst[i + 2] = (uint16_t)((pix >> 32) & 0xFFFF);
        dst[i + 3] = (uint16_t)((pix >> 48) & 0xFFFF);
    }
}
