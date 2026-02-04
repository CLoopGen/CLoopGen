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
    int total_elements = w * (((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)) - block_h * mb_y);
    IDWTELEM *ptr = buf + block_h * mb_y * w;
    int offset = 0;

    for (int i = 0; i < total_elements; i++, offset++) {
        if (offset >= w) {
            offset = 0;
            ptr += w - w; // No vertical skip, simulate row-by-row via flat traversal
        }
        ptr[offset] -= 128 << 4;
    }
}
