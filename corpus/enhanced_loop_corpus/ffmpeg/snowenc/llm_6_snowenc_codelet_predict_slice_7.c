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
    IDWTELEM *local_buf = buf;
    int shift_val = 4;
    int subtract_val = 128 << shift_val;
    int row_base;
    for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y++) {
        row_base = y * w;
        for (x = 0; x < w; x++) {
            local_buf[x + row_base] -= subtract_val;
        }
    }
}
