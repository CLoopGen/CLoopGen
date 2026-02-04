#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *src_cached = src;
uint8_t *dst_cached = dst;
int32_t offset = 0;

for (cnt = (height / 4); cnt--;) {
    // Introduce WAW and WAR dependencies via temporary accumulation
    uint8_t accum = 0;
    accum += src_cached[offset + 0 * src_stride];
    accum += src_cached[offset + 1 * src_stride];
    accum += src_cached[offset + 2 * src_stride];
    accum += src_cached[offset + 3 * src_stride];

    // Store accumulated value to four destination locations with artificial dependence
    dst_cached[offset + 0 * dst_stride] = accum++;
    dst_cached[offset + 1 * dst_stride] = accum++;
    dst_cached[offset + 2 * dst_stride] = accum++;
    dst_cached[offset + 3 * dst_stride] = accum;

    offset += 4 * src_stride;
}

// Update original pointers after loop
src += (4 * src_stride) * (height / 4);
dst += (4 * dst_stride) * (height / 4);
}
