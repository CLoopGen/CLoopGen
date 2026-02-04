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
uint8_t local_src_cache[32];
for (int i = 0; i < 32; i++) {
    local_src_cache[i] = src[i + (8 + 8 + 1)];
}
for (y = 0; y < 8; y++) {
    for (x = 0; x < 8; x++) {
        int index = (2 * y + x + 2);
        dst[x] = local_src_cache[(index > 15) ? 15 : index];
    }
    dst += stride;
}
}
