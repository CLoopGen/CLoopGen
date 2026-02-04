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
    for (y = block_h * mb_y; y < h && y < block_h * (mb_y + 1); y++) {
        for (x = 0; x < w; x++) {
            if ((x + y) % 2 == 0) {
                buf[x + y * w] -= 128 << 4;
            }
        }
    }
}
