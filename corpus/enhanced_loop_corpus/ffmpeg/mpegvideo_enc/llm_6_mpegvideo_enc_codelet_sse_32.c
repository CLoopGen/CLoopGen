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
    int temp_acc = 0;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int idx = x + y * stride;
            int diff = src1[idx] - src2[idx];
            temp_acc += sq[diff];
        }
    }
    acc = temp_acc;
}
