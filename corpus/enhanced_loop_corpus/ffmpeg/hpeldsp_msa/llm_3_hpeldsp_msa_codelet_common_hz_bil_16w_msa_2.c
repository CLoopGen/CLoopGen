#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    uint8_t *src_base = src;
    uint8_t *dst_base = dst;
    int offset;
    // Use consecutive memory access with indirect indexing via offsets
    for (offset = 0; offset < 8; offset += 2) {
        int src_idx = offset * src_stride;
        int dst_idx = offset * dst_stride;
        {
            {
                {
                    dst_base[dst_idx]     = src_base[src_idx];
                    dst_base[dst_idx + 1] = src_base[src_idx + 1];
                }
                ;
                {
                    dst_base[dst_idx + 2] = src_base[src_idx + 2];
                    dst_base[dst_idx + 3] = src_base[src_idx + 3];
                }
                ;
            }
            ;
            {
                {
                    dst_base[dst_idx + dst_stride]     = src_base[src_idx + src_stride];
                    dst_base[dst_idx + dst_stride + 1] = src_base[src_idx + src_stride + 1];
                }
                ;
                {
                    dst_base[dst_idx + dst_stride + 2] = src_base[src_idx + src_stride + 2];
                    dst_base[dst_idx + dst_stride + 3] = src_base[src_idx + src_stride + 3];
                }
                ;
            }
            ;
        }
    }
    src += (8 * src_stride);
    dst += (8 * dst_stride);
    // Second pass with transposed write pattern: write blocks of 4x4 using strided reads
    {
        {
            {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
                dst[3] = src[3];
            }
            {
                dst[dst_stride] = src[src_stride];
                dst[dst_stride + 1] = src[src_stride + 1];
                dst[dst_stride + 2] = src[src_stride + 2];
                dst[dst_stride + 3] = src[src_stride + 3];
            }
        }
        ;
        {
            {
                dst[2 * dst_stride] = src[2 * src_stride];
                dst[2 * dst_stride + 1] = src[2 * src_stride + 1];
            }
            ;
            {
                dst[2 * dst_stride + 2] = src[2 * src_stride + 2];
                dst[2 * dst_stride + 3] = src[2 * src_stride + 3];
            }
            ;
        }
        ;
    }
    ;
    dst += (4 * dst_stride);
    {
        {
            {
                dst[0] = src[4 * src_stride];
                dst[1] = src[4 * src_stride + 1];
            }
            {
                dst[2] = src[4 * src_stride + 2];
                dst[3] = src[4 * src_stride + 3];
            }
        }
        ;
        {
            {
                dst[dst_stride] = src[5 * src_stride];
                dst[dst_stride + 1] = src[5 * src_stride + 1];
            }
            ;
            {
                dst[dst_stride + 2] = src[5 * src_stride + 2];
                dst[dst_stride + 3] = src[5 * src_stride + 3];
            }
            ;
        }
        ;
    }
    ;
    dst += (4 * dst_stride);
}
}
