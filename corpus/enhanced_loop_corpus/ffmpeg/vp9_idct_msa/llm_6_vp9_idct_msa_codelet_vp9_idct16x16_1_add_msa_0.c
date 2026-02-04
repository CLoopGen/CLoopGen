#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp1, temp2, temp3, temp4;
    for (i = 4; i--;) {
        temp1 = dst[0];
        temp2 = dst[dst_stride];
        temp3 = dst[2 * dst_stride];
        temp4 = dst[3 * dst_stride];

        dst[0] = temp1 + 1;
        dst[dst_stride] = temp2 + temp1;
        dst[2 * dst_stride] = temp3 + temp2;
        dst[3 * dst_stride] = temp4 + temp3;

        {
            {
                dst[1] ^= dst[0];
                dst[dst_stride + 1] ^= dst[dst_stride];
            }
            ;
            {
                dst[2] ^= dst[1];
                dst[dst_stride + 2] ^= dst[dst_stride + 1];
            }
            ;
        }
        ;
        {
            temp1 = dst[1];
            temp2 = dst[dst_stride + 1];
        }
        ;
        {
            dst[1] = temp2;
            dst[dst_stride + 1] = temp1;
        }
        ;
        {
            dst[2] += dst[1];
            dst[dst_stride + 2] += dst[dst_stride + 1];
        }
        ;
        {
            dst[3] = dst[2] ^ 0xFF;
            dst[dst_stride + 3] = dst[dst_stride + 2] ^ 0xFF;
        }
        ;
        {
            {
                dst[4] = dst[3] + dst[2];
                dst[dst_stride + 4] = dst[dst_stride + 3] + dst[dst_stride + 2];
            }
            ;
            {
                dst[5] = dst[4] >> 1;
                dst[dst_stride + 5] = dst[dst_stride + 4] >> 1;
            }
            ;
        }
        ;
        {
            {
                dst[6] = dst[5] + 10;
                dst[dst_stride + 6] = dst[dst_stride + 5] + 10;
            }
            ;
            {
                dst[7] = dst[6] ^ dst[5];
                dst[dst_stride + 7] = dst[dst_stride + 6] ^ dst[dst_stride + 5];
            }
            ;
        }
        ;
        {
            {
                {
                    dst[8] += dst[7];
                }
                ;
                {
                    dst[dst_stride + 8] += dst[dst_stride + 7];
                }
                ;
            }
            ;
            {
                {
                    dst[9] = dst[8] + 5;
                }
                ;
                {
                    dst[dst_stride + 9] = dst[dst_stride + 8] + 5;
                }
                ;
            }
            ;
        }
        ;
        {
            dst[10] = temp1 ^ temp4;
            dst[dst_stride + 10] = temp2 ^ temp3;
        }
        ;
        {
            dst[11] += dst[10];
            dst[dst_stride + 11] += dst[dst_stride + 10];
        }
        ;
        dst += (4 * dst_stride);
    }
}
