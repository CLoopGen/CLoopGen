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
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height / 16); cnt--;) {
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                {
                }
                ;
                {
                }
                ;
                src += src_stride;
                dst_dup += dst_stride;
                {
                }
                {
                }
                ;
                {
                }
                ;
                dst += dst_stride;
            }
            src += 3 * src_stride;
            dst_dup += 3 * dst_stride;
            dst += 3 * dst_stride;
        }
        src += 12 * src_stride;
        dst_dup += 12 * dst_stride;
        dst += 12 * dst_stride;
    }
}
