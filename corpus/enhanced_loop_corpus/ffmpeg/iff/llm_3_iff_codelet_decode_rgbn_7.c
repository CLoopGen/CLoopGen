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
    // Variant 2: Strided memory access – process every other pixel, then fill in gaps
    uint16_t *base = (uint16_t *)dst;
    int stride = 2;
    int total_pixels = width * height;
    int count = 0;
    for (i = 0; i < length; i++) {
        int linear_index = (y * width + x) % total_pixels;
        int strided_index = (linear_index / stride) + (linear_index % stride) * ((total_pixels + stride - 1) / stride);
        if (strided_index < total_pixels) {
            *(base + strided_index) = pixel;
        }
        x += 1;
        if (x >= width) {
            y += 1;
            if (y >= height)
                return;
            x = 0;
        }
    }
}
