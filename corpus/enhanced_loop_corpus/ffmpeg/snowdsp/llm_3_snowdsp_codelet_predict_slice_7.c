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



void loop(){
    // Variant 2: Consecutive and Blocked Memory Access (Loop Interchange + Linear Traversal)
    // Flatten the loop into a single loop with consecutive memory access pattern
    // to improve cache locality by accessing elements in increasing order.
    int start_offset = (block_h * mb_y) * w;
    int end_y = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);
    int total_elements = (end_y - block_h * mb_y) * w;

    for (int i = 0; i < total_elements; i++) {
        buf[start_offset + i] -= 128 << 4;
    }
}
