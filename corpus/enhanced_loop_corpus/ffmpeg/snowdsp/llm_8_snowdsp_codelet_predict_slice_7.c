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
    int start_y = block_h * mb_y;
    int end_y = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);
    int stride = w;
    IDWTELEM *base_ptr = buf + start_y * stride;
    int shift_val = 4;

    for (int i = 0; i < (end_y - start_y); i++) {
        IDWTELEM *row = base_ptr + i * stride;
        for (int j = 0; j < w; j += 4) {
            row[j] -= 128 << shift_val;
            if (j + 1 < w) row[j + 1] -= 128 << shift_val;
            if (j + 2 < w) row[j + 2] -= 128 << shift_val;
            if (j + 3 < w) row[j + 3] -= 128 << shift_val;
        }
    }
}
