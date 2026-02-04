#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern  unsigned int color;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_buffer[256];
    int block_size = (b_w < 256) ? b_w : 256;
    for (y = 0; y < b_h; y++) {
        uint8_t *row = &dst[y * stride];
        for (x = 0; x < b_w; x += block_size) {
            int remaining = b_w - x;
            int current_block = (remaining < block_size) ? remaining : block_size;
            for (int i = 0; i < current_block; i++) {
                temp_buffer[i] = (uint8_t)color;
            }
            for (int i = 0; i < current_block; i++) {
                row[x + i] = temp_buffer[i];
            }
        }
    }
}
