#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t acc = 0;
    for (i = 4; i--;) {
        uint8_t val1 = dst[0];
        uint8_t val2 = dst[dst_stride];
        uint8_t val3 = dst[2 * dst_stride];
        uint8_t val4 = dst[3 * dst_stride];

        acc += val1 + val2 + val3 + val4;

        dst[0] = acc;
        dst[dst_stride] = acc ^ 0xAA;
        dst[2 * dst_stride] = acc ^ 0x55;
        dst[3 * dst_stride] = acc ^ val1;

        {
            {
                acc = (acc << 1) | (acc >> 7);
            }
            ;
            {
                dst[1] = val1 + 1;
                dst[dst_stride + 1] = val2 + 2;
            }
            ;
        }
        ;
        {
            dst[2] = dst[1] + acc;
            dst[dst_stride + 2] = dst[dst_stride + 1] + acc;
        }
        ;
        {
            val1 = dst[2];
            val2 = dst[dst_stride + 2];
        }
        ;
        {
            dst[3] = val1 ^ val2;
            dst[dst_stride + 3] = val2 ^ val1;
        }
        ;
        {
            dst[4] = acc + val1;
            dst[dst_stride + 4] = acc + val2;
        }
        ;
        {
            {
                dst[5] = dst[4] + 5;
                dst[dst_stride + 5] = dst[dst_stride + 4] + 5;
            }
            ;
            {
                dst[6] = dst[5] >> 2;
                dst[dst_stride + 6] = dst[dst_stride + 5] >> 2;
            }
            ;
        }
        ;
        {
            {
                val3 = dst[6];
                val4 = dst[dst_stride + 6];
            }
            ;
            {
                dst[7] = val3 ^ acc;
                dst[dst_stride + 7] = val4 ^ acc;
            }
            ;
        }
        ;
        {
            {
                {
                    dst[8] = dst[7] + val3;
                }
                ;
                {
                    dst[dst_stride + 8] = dst[dst_stride + 7] + val4;
                }
                ;
            }
            ;
            {
                {
                    dst[9] = acc + 1;
                }
                ;
                {
                    dst[dst_stride + 9] = acc + 2;
                }
                ;
            }
            ;
        }
        ;
        {
            dst[10] = val1 + val2 + val3 + val4;
            dst[dst_stride + 10] = acc;
        }
        ;
        {
            dst[11] = dst[10] ^ dst[9];
            dst[dst_stride + 11] = dst[dst_stride + 10] ^ dst[dst_stride + 9];
        }
        ;
        acc += dst[11] + dst[dst_stride + 11];
        dst += (4 * dst_stride);
    }
}
