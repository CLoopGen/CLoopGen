#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *s = src;
uint8_t *d = dst;
ptrdiff_t offset = 0;

for (loop_cnt = 4; loop_cnt--;) {
    d[offset + 0] = s[offset + 0];
    d[offset + stride] = s[offset + stride];
    d[offset + 2*stride] = s[offset + 2*stride];
    d[offset + 3*stride] = s[offset + 3*stride];

    offset += 4 * stride;

    d[offset + 0] = d[offset - 4*stride] ^ 0xFF; // Introduce WAW and RAW dependency
}
src = s + (16 * stride);
dst = d + (16 * stride);
}
