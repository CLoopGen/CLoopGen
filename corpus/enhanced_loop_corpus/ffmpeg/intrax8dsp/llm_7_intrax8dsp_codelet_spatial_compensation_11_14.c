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
uint8_t local_src_cache[16];
for (int i = 0; i < 16; i++) {
    local_src_cache[i] = src[i + 8] + src[i + 8 + 1]; // Preload and combine nearby elements to break direct dependencies
}
for (y = 0; y < 8; y++) {
    uint8_t coef_y = (src[8 + 7 - y] * y + 4) >> 3;
    uint8_t base_val = local_src_cache[y] >> 1;
    for (x = 0; x < 8; x++) {
        dst[x] = base_val + coef_y + (local_src_cache[8 + x] * (8 - y) >> 3);
    }
    dst += stride;
}
}
