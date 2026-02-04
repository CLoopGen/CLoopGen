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
    int stride = w;
    IDWTELEM *base_ptr = buf + y_start * stride;
    IDWTELEM offset = 128 << 4;

    for (int idx = 0; idx < (y_end - y_start) * w; idx++) {
        base_ptr[idx] -= offset;
    }
}
