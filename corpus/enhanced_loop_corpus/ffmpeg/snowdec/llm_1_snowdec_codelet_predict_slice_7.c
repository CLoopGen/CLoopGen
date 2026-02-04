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
    for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y++) {
        for (int tile_y = y; tile_y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); tile_y++) {
            for (x = 0; x < w; x++) {
                buf[x + tile_y * w] -= 128 << 4;
            }
        }
    }
}
