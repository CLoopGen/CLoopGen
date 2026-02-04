#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i += 2) {
        for (int k = 0; k < 2 && (i + k) < h; k++) {
            int idx = i + k;
            uint8_t *d = dst + k * stride;
            uint8_t *s = src + k * stride;
            d[0] = (((d[0]) + (((A * s[0]) + 32) >> 6) + 1) >> 1);
            d[1] = (((d[1]) + (((A * s[1]) + 32) >> 6) + 1) >> 1);
        }
        dst += 2 * stride;
        src += 2 * stride;
    }
}
