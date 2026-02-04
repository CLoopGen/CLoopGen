#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        int base_idx = (8 + 8 + 1);
        for (x = 0; x < 8; x++) {
            int index = 2 * y + x + 2;
            if (index >= 15) {
                dst[x] = src[base_idx + 15];
            } else {
                dst[x] = src[base_idx + index];
            }
        }
        dst += stride;
    }
}
