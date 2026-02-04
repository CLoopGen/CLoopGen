#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_limit = (srcWidth - 1) >> 1;
    for (int i = 0; i < outer_limit; i++) {
        for (int j = 0; j < 2; j++) {
            int x = (i << 1) + j;
            if (x >= srcWidth - 1) break;
            dst[2 * x + 1] = (3 * src[x] + src[x + 1]) >> 2;
            dst[2 * x + 2] = (src[x] + 3 * src[x + 1]) >> 2;
        }
    }
}
