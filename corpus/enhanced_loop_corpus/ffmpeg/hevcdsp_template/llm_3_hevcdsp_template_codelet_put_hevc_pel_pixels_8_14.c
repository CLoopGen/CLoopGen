#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 2nd element in two passes (even then odd indices)
    int16_t *dst_base = dst;
    uint8_t *src_row = src;
    for (y = 0; y < height; y++) {
        // First pass: even indices
        for (x = 0; x < width; x += 2) {
            dst_base[x] = src_row[x] << (14 - 8);
        }
        // Second pass: odd indices
        for (x = 1; x < width; x += 2) {
            dst_base[x] = src_row[x] << (14 - 8);
        }
        src_row += srcstride;
        dst_base += 64;
    }
}
