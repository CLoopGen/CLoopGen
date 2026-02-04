#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (left-to-right), access elements with a stride of 2,
    // processing even and odd indices in separate passes to create strided access.
    int stride = 2;
    int end_y = (h > block_h * (mb_y + 1)) ? block_h * (mb_y + 1) : h;

    for (y = block_h * mb_y; y < end_y; y++) {
        // First pass: even indices
        for (x = 0; x < w; x += stride) {
            buf[x + y * w] -= 128 << 4;
        }
        // Second pass: odd indices
        for (x = 1; x < w; x += stride) {
            buf[x + y * w] -= 128 << 4;
        }
    }
}
