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
    int offset = y_start * w;
    int total_elements = (y_end - y_start) * w;
    int shift_val = 128 << 4;

    for (int idx = 0; idx < total_elements; idx++) {
        buf[offset + idx] -= shift_val;
    }
}
