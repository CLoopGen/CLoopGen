#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern int height;
extern int linesize;
extern int x;
extern int y;
extern int i;
extern int length;
extern uint32_t pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < length; i++) {
        int curr_x = x + (i % stride);
        int curr_y = y + (i / stride);
        if (curr_y >= height) return;
        if (curr_x >= width) {
            curr_y += 1;
            curr_x = 0;
            if (curr_y >= height) return;
        }
        *(uint16_t *)(dst + curr_y * linesize + curr_x * sizeof(uint16_t)) = pixel;
    }
    x = (x + length) % width;
    y = (y + (x / width)) % height;
}
