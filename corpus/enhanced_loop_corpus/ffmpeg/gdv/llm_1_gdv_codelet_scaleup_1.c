#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w > 7) {
        int limit = w - 7;
        for (x = 0; x < limit; x += 8) {
            int half_x = x >> 1;
            uint8_t val0 = src[half_x + 0];
            uint8_t val1 = src[half_x + 1];
            uint8_t val2 = src[half_x + 2];
            uint8_t val3 = src[half_x + 3];
            dst[x + 0] = val0;
            dst[x + 1] = val0;
            dst[x + 2] = val1;
            dst[x + 3] = val1;
            dst[x + 4] = val2;
            dst[x + 5] = val2;
            dst[x + 6] = val3;
            dst[x + 7] = val3;
        }
    }
}
