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
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int index = x + y * 4;
            dots[k++] = block[x * 4 + y * stride] * dirr + block[x * 4 + 1 + y * stride] * dirg + block[x * 4 + 2 + y * stride] * dirb;
            if (x == 0) {
                stops[y] = color[y * 4] * dirr + color[y * 4 + 1] * dirg + color[y * 4 + 2] * dirb;
            }
        }
    }
}
