#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 1); loop_cnt--;) {
    const int block_size = 8;
    ptrdiff_t indices[] = {0, 2, 4, 6, 1, 3, 5, 7}; // Interleaved access pattern

    for (int blk = 0; blk < block_size; ++blk) {
        ptrdiff_t idx = indices[blk];
        dst[idx + 0 * dst_stride] = src[idx + 0 * src_stride];
        dst[idx + 1 * dst_stride] = src[idx + 1 * src_stride];
    }

    {
        ptrdiff_t idx = indices[0];
        dst[idx + 2 * dst_stride] = src[idx + 2 * src_stride];
        dst[idx + 3 * dst_stride] = src[idx + 3 * src_stride];
    }
    ;
    {
        ptrdiff_t idx = indices[1];
        dst[idx + 2 * dst_stride] = src[idx + 2 * src_stride];
        dst[idx + 3 * dst_stride] = src[idx + 3 * src_stride];
    }
    ;
    {
        ptrdiff_t idx = indices[2];
        dst[idx + 2 * dst_stride] = src[idx + 2 * src_stride];
        dst[idx + 3 * dst_stride] = src[idx + 3 * src_stride];
    }
    ;
    {
        {
            ptrdiff_t idx = indices[3];
            dst[idx + 2 * dst_stride] = src[idx + 2 * src_stride];
            dst[idx + 3 * dst_stride] = src[idx + 3 * src_stride];
        }
        ;
        {
            ptrdiff_t idx = indices[4];
            dst[idx + 2 * dst_stride] = src[idx + 2 * src_stride];
            dst[idx + 3 * dst_stride] = src[idx + 3 * src_stride];
        }
        ;
    }
    ;
    {
        {
            ptrdiff_t idx = indices[5];
            dst[idx + 2 * dst_stride] = src[idx + 2 * src_stride];
            dst[idx + 3 * dst_stride] = src[idx + 3 * src_stride];
        }
        ;
        {
            ptrdiff_t idx = indices[6];
            dst[idx + 2 * dst_stride] = src[idx + 2 * src_stride];
            dst[idx + 3 * dst_stride] = src[idx + 3 * src_stride];
        }
        ;
    }
    ;
    {
        ptrdiff_t idx = indices[7];
        dst[idx + 2 * dst_stride] = src[idx + 2 * src_stride];
        dst[idx + 3 * dst_stride] = src[idx + 3 * src_stride];
    }
    ;
    src += (2 * src_stride);
    {
        ptrdiff_t idx = indices[0];
        dst[idx + 4 * dst_stride] = src[idx + 4 * src_stride];
        dst[idx + 5 * dst_stride] = src[idx + 5 * src_stride];
    }
    ;
    {
        ptrdiff_t idx = indices[1];
        dst[idx + 4 * dst_stride] = src[idx + 4 * src_stride];
        dst[idx + 5 * dst_stride] = src[idx + 5 * src_stride];
    }
    ;
    {
        ptrdiff_t idx = indices[2];
        dst[idx + 4 * dst_stride] = src[idx + 4 * src_stride];
        dst[idx + 5 * dst_stride] = src[idx + 5 * src_stride];
    }
    ;
    {
        {
            ptrdiff_t idx = indices[3];
            dst[idx + 4 * dst_stride] = src[idx + 4 * src_stride];
            dst[idx + 5 * dst_stride] = src[idx + 5 * src_stride];
        }
        ;
        {
            ptrdiff_t idx = indices[4];
            dst[idx + 4 * dst_stride] = src[idx + 4 * src_stride];
            dst[idx + 5 * dst_stride] = src[idx + 5 * src_stride];
        }
        ;
    }
    ;
    {
        {
            ptrdiff_t idx = indices[5];
            dst[idx + 4 * dst_stride] = src[idx + 4 * src_stride];
            dst[idx + 5 * dst_stride] = src[idx + 5 * src_stride];
        }
        ;
        {
            ptrdiff_t idx = indices[6];
            dst[idx + 4 * dst_stride] = src[idx + 4 * src_stride];
            dst[idx + 5 * dst_stride] = src[idx + 5 * src_stride];
        }
        ;
    }
    ;
    dst += 2 * dst_stride;
}
}
