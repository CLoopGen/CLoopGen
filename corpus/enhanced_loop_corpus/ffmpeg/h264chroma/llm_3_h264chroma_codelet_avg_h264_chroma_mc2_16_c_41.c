#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *d = dst;
    uint16_t *s = src;
    for (i = 0; i < h; i++) {
        size_t j;
        for (j = 0; j < 2; j++) {
            d[j] = ((d[j] + ((A * s[j] + 32) >> 6) + 1) >> 1);
        }
        d += stride;
        s += stride;
    }
}
