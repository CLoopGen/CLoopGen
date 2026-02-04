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
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int index = x + y * stride;
        uint8_t val1 = src1[index];
        uint8_t val2 = src2[index];
        if (val1 >= val2) {
            acc += sq[val1 - val2];
        } else {
            acc += sq[val2 - val1];
        }
    }
}
}
