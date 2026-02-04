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
    int y_start = block_h * mb_y;
    int y_end = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);

    for (y = y_start; y < y_end; y++) {
        int row_offset = y * w;
        IDWTELEM val = 128 << 4;
        for (x = 0; x < w; x += 4) {
            // Unroll by 4 to increase computational intensity
            buf[x + 0 + row_offset] -= val;
            buf[x + 1 + row_offset] -= val;
            if (x + 2 >= w) break;
            buf[x + 2 + row_offset] -= val;
            if (x + 3 >= w) break;
            buf[x + 3 + row_offset] -= val;
        }
    }
}
