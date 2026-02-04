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
    uint8_t *d = dst;
    uint8_t *s = src;
    for (i = 0; i < h; i++) {
        d[0] = (((A * s[stride]) + 32) >> 6);
        d[1] = (((A * s[0]) + 32) >> 6);
        d += stride;
        s += stride;
    }
}
