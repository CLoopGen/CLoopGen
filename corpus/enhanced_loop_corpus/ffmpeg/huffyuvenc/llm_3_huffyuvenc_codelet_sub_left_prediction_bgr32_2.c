#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;
extern int min_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed processing order
    for (i = min_width - 1; i >= 0; i--) {
        const int idx = i * 4;
        const int rt = src[idx + 2];
        const int gt = src[idx + 1];
        const int bt = src[idx + 0];
        const int at = src[idx + 3];
        dst[idx + 2] = rt - r;
        dst[idx + 1] = gt - g;
        dst[idx + 0] = bt - b;
        dst[idx + 3] = at - a;
        r = rt;
        g = gt;
        b = bt;
        a = at;
    }
}
