#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *block;
extern uint8_t *restrict pixels;
extern ptrdiff_t line_size;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of incrementing block and pixels sequentially per element,
    // access them with a fixed stride (e.g., every second element forward, then adjust)
    // Here we simulate a strided write by processing elements with step size 2,
    // then filling in the gaps. However, to maintain correctness over 8x8,
    // we use temporary pointers with strided traversal but still cover all indices.

    int16_t *block_base = block;
    uint8_t *pixels_base = pixels;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j += 2) {
            // Process even indices first with stride 2
            int16_t val = *(block_base + i * 8 + j);
            if (val < -128)
                *(pixels_base + i * line_size + j) = 0;
            else if (val > 127)
                *(pixels_base + i * line_size + j) = 255;
            else
                *(pixels_base + i * line_size + j) = (uint8_t)(val + 128);

            // Process odd index if within bounds
            if (j + 1 < 8) {
                val = *(block_base + i * 8 + j + 1);
                if (val < -128)
                    *(pixels_base + i * line_size + j + 1) = 0;
                else if (val > 127)
                    *(pixels_base + i * line_size + j + 1) = 255;
                else
                    *(pixels_base + i * line_size + j + 1) = (uint8_t)(val + 128);
            }
        }
    }
}
