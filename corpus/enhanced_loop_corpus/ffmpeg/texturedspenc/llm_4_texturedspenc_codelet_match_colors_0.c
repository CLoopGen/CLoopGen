#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int dirr;
extern int dirg;
extern int dirb;
extern int dots[16];
extern int stops[4];
extern int x;
extern int y;
extern int k;
extern uint8_t color[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    k = 0;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int index = x * 4 + y * stride;
            if ((x + y) % 2 == 0) {
                dots[k++] = block[0 + index] * dirr + block[1 + index] * dirg + block[2 + index] * dirb;
            }
        }
        int color_index = y * 4;
        stops[y] = color[0 + color_index] * dirr + color[1 + color_index] * dirg + color[2 + color_index] * dirb;
    }
}
