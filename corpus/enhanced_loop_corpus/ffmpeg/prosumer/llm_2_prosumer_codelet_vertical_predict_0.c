#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *dst;
extern  uint32_t *src;
extern int stride;
extern int height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < height; i++) {
    uint32_t *dst_offset = dst + i * (stride >> 2);
    uint32_t *src_offset = src + i * (stride >> 2);
    for (int j = 0; j < stride >> 2; j++) {
        dst_offset[j] = (((src_offset[j] >> 3) + (1061109567 & dst_offset[j])) << 3) & 4244438268U;
    }
}
}
