#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i <= size - 3; i += 3) {
        r = ((r + last[i + 0]) >> 1) + src[i + 0];
        g = ((g + last[i + 0]) >> 1) + src[i + 0];  // Introduce RAW dependency on i+0 and create WAW on g using same index
        b = ((b + last[i + 1]) >> 1) + src[i + 1];  // Shift data flow: now depends on different timing
        a = ((a + last[i + 2]) >> 1) + src[i + 2];

        dst[i + 0] = r & 255;
        dst[i + 1] = g & 255;
        dst[i + 2] = b & 255;
        if (i + 3 < size) {
            dst[i + 3] = a & 255;
        }
    }
}
