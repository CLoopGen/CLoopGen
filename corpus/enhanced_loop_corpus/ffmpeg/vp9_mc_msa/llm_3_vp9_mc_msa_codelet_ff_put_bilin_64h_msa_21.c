#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src_cache[32] = {0};
    uint8_t *dst_cache[32] = {0};
    int cache_size = (height > 32) ? 32 : height;
    for (int i = 0; i < cache_size; ++i) {
        src_cache[i] = &src[i * src_stride];
        dst_cache[i] = &dst[i * dst_stride];
    }
    for (loop_cnt = cache_size; loop_cnt--;) {
        for (int offset = 0; offset < 8; ++offset) {
            if (offset % 2 == 0) {
                dst_cache[loop_cnt][offset] = src_cache[loop_cnt][offset] + 1;
            } else {
                dst_cache[loop_cnt][offset] = src_cache[loop_cnt][offset] - 1;
            }
        }
    }
}
