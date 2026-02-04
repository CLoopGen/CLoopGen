#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i <= size - 8; i += 8) {
        dst[i + 0] = r = ((r) + (src[i + 0]));
        dst[i + 2] = g = ((g) + (src[i + 2]));
        dst[i + 4] = b = ((b) + (src[i + 4]));
        dst[i + 6] = a = ((a) + (src[i + 6]));
        r = (r << 1) - (r >> 2);
        g = (g << 1) - (g >> 2);
        b = (b << 1) - (b >> 2);
        a = (a << 1) - (a >> 2);
        dst[i + 1] = r = ((r) + (src[i + 1]));
        dst[i + 3] = g = ((g) + (src[i + 3]));
        dst[i + 5] = b = ((b) + (src[i + 5]));
        dst[i + 7] = a = ((a) + (src[i + 7]));
    }
}
