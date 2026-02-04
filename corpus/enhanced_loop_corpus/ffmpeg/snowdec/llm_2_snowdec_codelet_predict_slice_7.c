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
    // Instead of row-major (consecutive) access, traverse with a stride equal to 'w'
    // This changes spatial locality and may affect cache performance.
    int start_y = block_h * mb_y;
    int end_y = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);
    
    for (x = 0; x < w; x++) {
        for (y = start_y; y < end_y; y++) {
            buf[x + y * w] -= 128 << 4;
        }
    }
}
