#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src1;
extern uint8_t *src2;
extern int w;
extern int h;
extern int stride;
extern  uint32_t *sq;
extern int acc;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    acc = 0;
    for (y = 0; y < h; y++) {
        int row_sum = 0;
        for (x = 0; x < w; x++) {
            int idx = x + y * stride;
            row_sum += sq[src1[idx] - src2[idx]];
        }
        acc += row_sum;
    }
}
