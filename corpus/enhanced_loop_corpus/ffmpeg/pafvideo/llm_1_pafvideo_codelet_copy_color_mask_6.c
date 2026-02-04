#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern uint8_t color;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int bit_pos = (i < 4) ? (7 - i) : (3 - (i - 4));
    int dst_idx = (i < 4) ? i : (width + (i - 4));
    if (i >= 4 && (i - 4) >= 4) continue;
    if (mask & (1 << bit_pos))
        dst[dst_idx] = color;
}
}
