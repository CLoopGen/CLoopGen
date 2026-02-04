#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *local_src = src;
uint8_t *local_dst = dst;
int local_height = height;

for (cnt = (local_height >> 2); cnt--;) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            local_dst[i * dst_stride + j] = local_src[i * src_stride + j] ^ 0xFF;
        }
    }

    local_src += (4 * src_stride);
    local_dst += (4 * dst_stride);
}

src = local_src;
dst = local_dst;
}
