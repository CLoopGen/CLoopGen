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
    IDWTELEM *base = buf + y_start * stride;
    for (int i = 0; i < (y_end - y_start); i++) {
        IDWTELEM *row = base + i * stride;
        for (int x = 0; x < w; x += 4) {
            row[x]     -= 128 << 4;
            if (x + 1 < w) row[x + 1] -= 128 << 4;
            if (x + 2 < w) row[x + 2] -= 128 << 4;
            if (x + 3 < w) row[x + 3] -= 128 << 4;
        }
    }
}
