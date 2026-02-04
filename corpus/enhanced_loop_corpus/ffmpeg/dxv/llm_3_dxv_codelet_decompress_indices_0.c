#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (block = 0; block < 2; block++) {
        const uint8_t *s = &src[0];
        uint8_t *d = &dst[0];
        int tmp = (s[2] << 16) | (s[1] << 8) | s[0];
        for (i = 0; i < 8; i += 2) {
            d[i + 0] = (tmp >> ((i + 0) * 3)) & 7;
            if (i + 1 < 8) {
                d[i + 1] = (tmp >> ((i + 1) * 3)) & 7;
            }
        }
        src += 3;
        dst += 8;
    }
}
