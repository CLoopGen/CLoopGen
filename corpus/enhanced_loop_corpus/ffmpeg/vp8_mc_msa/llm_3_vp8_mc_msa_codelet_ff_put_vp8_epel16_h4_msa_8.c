#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Change to consecutive memory access with local array for temporal locality
    uint8_t temp_block[16]; // Simulate tiling/blocking for cache efficiency

    // Load a transposed tile from source using strided reads but store consecutively
    temp_block[0]  = src[0];
    temp_block[1]  = src[src_stride];
    temp_block[2]  = src[2 * src_stride];
    temp_block[3]  = src[3 * src_stride];

    temp_block[4]  = src[4];
    temp_block[5]  = src[src_stride + 4];
    temp_block[6]  = src[2 * src_stride + 4];
    temp_block[7]  = src[3 * src_stride + 4];

    temp_block[8]  = src[8];
    temp_block[9]  = src[src_stride + 8];
    temp_block[10] = src[2 * src_stride + 8];
    temp_block[11] = src[3 * src_stride + 8];

    temp_block[12] = src[12];
    temp_block[13] = src[src_stride + 12];
    temp_block[14] = src[2 * src_stride + 12];
    temp_block[15] = src[3 * src_stride + 12];

    // Store the block consecutively into destination
    for (int i = 0; i < 16; i++) {
        dst[i] = temp_block[i];
    }

    // Advance pointers
    src += 4 * src_stride;
    dst += 16; // Consecutive write stride instead of vertical
}
}
