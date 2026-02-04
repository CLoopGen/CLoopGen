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
    if (block_h <= 0 || w <= 0) return;
    int start_y = block_h * mb_y;
    int end_y = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);
    for (y = start_y; y < end_y; y++) {
        for (x = 0; x < w; x++) {
            if ((x + y * w) >= 0) {
                buf[x + y * w] -= 128 << 4;
            }
        }
    }
}
