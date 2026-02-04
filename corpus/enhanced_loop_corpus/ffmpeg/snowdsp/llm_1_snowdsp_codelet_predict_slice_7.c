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
    int total_elements = w * (((h > block_h * (mb_y + 1)) ? block_h * (mb_y + 1) : h) - block_h * mb_y);
    int idx;
    for (idx = 0; idx < total_elements; idx++) {
        int y_local = block_h * mb_y + idx / w;
        int x_local = idx % w;
        buf[x_local + y_local * w] -= 128 << 4;
    }
}
