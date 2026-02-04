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
    uint8_t temp1, temp2;
    {
        temp1 = src[0];
    }
    ;
    {
        temp2 = src[src_stride];
    }
    ;
    src += (2 * src_stride);
    {
        dst[0] = temp1 ^ 0xFF;
    }
    ;
    {
        dst[dst_stride] = temp2 ^ 0xFF;
    }
    ;
    {
        dst[1] = temp1;
    }
    ;
    {
        dst[dst_stride + 1] = temp2;
    }
    ;
    {
        dst[2] = temp1 + temp2;
    }
    ;
    {
        dst[dst_stride + 2] = temp1 ^ temp2;
    }
    ;
    {
        {
            {
                temp1 ^= dst[0];
            }
            ;
            {
                temp2 ^= dst[dst_stride];
            }
            ;
            {
                {
                    dst[3] = temp1;
                }
                ;
                {
                    dst[dst_stride + 3] = temp2;
                }
                ;
            }
            ;
            {
                {
                    temp1 += 1;
                }
                {
                    temp2 += 2;
                }
            }
            ;
            {
                dst[4] = temp1;
            }
            ;
            {
                dst[dst_stride + 4] = temp2;
            }
            ;
            {
                {
                    dst[5] = temp1 ^ temp2;
                }
                ;
                {
                    dst[dst_stride + 5] = temp1 + temp2;
                }
                ;
            }
            ;
        }
        ;
        {
            {
                temp1 = (temp1 << 1) | (temp1 >> 7);
            }
            ;
            {
                temp2 = (temp2 << 1) | (temp2 >> 7);
            }
            ;
            {
                {
                    dst[6] = temp1;
                }
                ;
                {
                    dst[dst_stride + 6] = temp2;
                }
                ;
            }
            ;
            {
                {
                    temp1 ^= 0xAA;
                }
                {
                    temp2 ^= 0x55;
                }
            }
            ;
            {
                dst[7] = temp1;
            }
            ;
            {
                dst[dst_stride + 7] = temp2;
            }
            ;
            {
                {
                    dst[8] = temp1 + 10;
                }
                ;
                {
                    dst[dst_stride + 8] = temp2 + 10;
                }
                ;
            }
            ;
        }
        ;
    }
    ;
    {
        {
            {
                dst[9] = temp1 ^ temp2;
            }
            ;
            {
                dst[dst_stride + 9] = temp2 ^ temp1;
            }
            ;
            {
                {
                    dst[10] = temp1;
                }
                ;
                {
                    dst[dst_stride + 10] = temp2;
                }
                ;
            }
            ;
            {
                {
                    temp1 += dst[0];
                }
                {
                    temp2 += dst[1];
                }
            }
            ;
            {
                dst[11] = temp1;
            }
            ;
            {
                dst[dst_stride + 11] = temp2;
            }
            ;
            {
                {
                    dst[12] = temp1 ^ 0xFF;
                }
                ;
                {
                    dst[dst_stride + 12] = temp2 ^ 0xFF;
                }
                ;
            }
            ;
        }
        ;
        {
            {
                temp1 = src[-src_stride] + temp1;
            }
            ;
            {
                temp2 = src[-src_stride + 1] + temp2;
            }
            ;
            {
                {
                    dst[13] = temp1;
                }
                ;
                {
                    dst[dst_stride + 13] = temp2;
                }
                ;
            }
            ;
            {
                {
                    temp1 -= 5;
                }
                {
                    temp2 -= 5;
                }
            }
            ;
            {
                dst[14] = temp1;
            }
            ;
            {
                dst[dst_stride + 14] = temp2;
            }
            ;
            {
                {
                    dst[15] = temp1 ^ temp2;
                }
                ;
                {
                    dst[dst_stride + 15] = temp1 + temp2;
                }
                ;
            }
            ;
        }
        ;
    }
    ;
    {
    }
    ;
    {
    }
    ;
    {
    }
    ;
    {
    }
    ;
    dst += (2 * dst_stride);
}
}
