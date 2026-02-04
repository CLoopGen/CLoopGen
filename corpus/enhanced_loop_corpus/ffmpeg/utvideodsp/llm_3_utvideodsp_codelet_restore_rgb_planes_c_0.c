#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_r;
extern uint8_t *src_g;
extern uint8_t *src_b;
extern ptrdiff_t linesize_r;
extern ptrdiff_t linesize_g;
extern ptrdiff_t linesize_b;
extern int width;
extern int height;
extern uint8_t r;
extern uint8_t g;
extern uint8_t b;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 2nd pixel first, then the offset (cache-friendly interleaving)
    for (j = 0; j < height; j++) {
        uint8_t *base_r = src_r;
        uint8_t *base_g = src_g;
        uint8_t *base_b = src_b;

        // First pass: even indices (0, 2, 4, ...)
        for (i = 0; i < width; i += 2) {
            r = base_r[i];
            g = base_g[i];
            b = base_b[i];
            base_r[i] = r + g - 128;
            base_b[i] = b + g - 128;
        }

        // Second pass: odd indices (1, 3, 5, ...)
        for (i = 1; i < width; i += 2) {
            r = base_r[i];
            g = base_g[i];
            b = base_b[i];
            base_r[i] = r + g - 128;
            base_b[i] = b + g - 128;
        }

        src_r += linesize_r;
        src_g += linesize_g;
        src_b += linesize_b;
    }
}
