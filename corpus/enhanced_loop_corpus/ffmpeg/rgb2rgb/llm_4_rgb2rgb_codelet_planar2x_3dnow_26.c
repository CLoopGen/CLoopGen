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
    if (srcWidth <= 1) return;
    for (x = 0; x < srcWidth - 1; x++) {
        if ((3 * src[x] + src[x + 1]) >= 4) {
            dst[2 * x + 1] = (3 * src[x] + src[x + 1]) >> 2;
        } else {
            dst[2 * x + 1] = 0;
        }
        if ((src[x] + 3 * src[x + 1]) >= 4) {
            dst[2 * x + 2] = (src[x] + 3 * src[x + 1]) >> 2;
        } else {
            dst[2 * x + 2] = 0;
        }
    }
}
