#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (int inner = 0; inner < 4; inner++) {
        for (x = 0; x < 1; x++) {
            dst[x + inner] = cm[(filter[2] * tmp[x + inner] - filter[1] * tmp[x + inner - 4] + filter[0] * tmp[x + inner - 8] + filter[3] * tmp[x + inner + 4] - filter[4] * tmp[x + inner + 8] + filter[5] * tmp[x + inner + 12] + 64) >> 7];
        }
    }
    dst += dststride;
    tmp += 4;
}
}
