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
for (cnt = (height / 12); cnt--;) {
    int32_t offset_src = 8 * src_stride;
    int32_t offset_dst = 8 * dst_stride;

    if (cnt % 2 == 0) {
        src += offset_src;
        {
            {
            };
            {
            };
        };
    } else {
        src += (4 * src_stride);
        {
            {
            };
        };
    }

    if (cnt > (height / 24)) {
        dst += offset_dst;
        {
            {
            };
            {
            };
        };
    } else {
        dst += (4 * dst_stride);
        {
            {
            };
        };
    }

    {
        {
        };
        {
        };
    };
}
}
