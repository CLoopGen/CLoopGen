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
    int y_end = (h > (block_h * (mb_y + 1))) ? (block_h * (mb_y + 1)) : h;
    for (y = y_start; y < y_end; y++) {
        x = 0;
        for (; x < w;) {
            buf[x + y * w] -= 128 << 4;
            x++;
        }
    }
}
