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
    for (; i <= size - 16; i += 16) {
        for (int offset = 0; offset < 16; offset += 4) {
            int idx = i + offset;
            dst[idx + 0] = r = (((((r) + (last[idx + 0])) >> 1) + (src[idx + 0])) & 255);
            if (4 == 1)
                continue;
            dst[idx + 1] = g = (((((g) + (last[idx + 1])) >> 1) + (src[idx + 1])) & 255);
            if (4 == 2)
                continue;
            dst[idx + 2] = b = (((((b) + (last[idx + 2])) >> 1) + (src[idx + 2])) & 255);
            if (4 == 3)
                continue;
            dst[idx + 3] = a = (((((a) + (last[idx + 3])) >> 1) + (src[idx + 3])) & 255);
        }
    }
}
