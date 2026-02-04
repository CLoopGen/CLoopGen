#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int w;
extern int i;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = w;
    if (limit > 16) limit = 16;
    for (i = 0; i < limit; i++) {
        const int rt = src[i * 3 + 0];
        const int gt = src[i * 3 + 1];
        const int bt = src[i * 3 + 2];
        dst[i * 3 + 0] = rt - r;
        dst[i * 3 + 1] = gt - g;
        dst[i * 3 + 2] = bt - b;
        r = rt;
        g = gt;
        b = bt;
    }
}
