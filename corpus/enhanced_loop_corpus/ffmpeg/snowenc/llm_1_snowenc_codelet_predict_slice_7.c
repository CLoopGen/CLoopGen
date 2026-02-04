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
    int index = (block_h * mb_y) * w;
    int y_end = ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h));
    int total_elements = (y_end - block_h * mb_y) * w;
    for (int i = 0; i < total_elements; i++) {
        buf[index + i] -= 128 << 4;
    }
}
