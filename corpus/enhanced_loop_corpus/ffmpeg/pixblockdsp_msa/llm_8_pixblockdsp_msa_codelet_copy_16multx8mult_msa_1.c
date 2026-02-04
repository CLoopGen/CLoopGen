#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern int32_t cnt;
extern int32_t loop_cnt;
extern  uint8_t *src_tmp;
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 3); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        {
            {
                uint64_t sum1 = 0, sum2 = 0;
                sum1 += *((uint32_t*)(src_tmp));
                sum2 += *((uint32_t*)(src_tmp + src_stride));
                sum1 += *((uint32_t*)(src_tmp + 2*src_stride));
                sum2 += *((uint32_t*)(src_tmp + 3*src_stride));
                *((uint32_t*)(dst_tmp)) = (uint32_t)(sum1 ^ sum2);
                *((uint32_t*)(dst_tmp + dst_stride)) = (uint32_t)(sum1 + sum2);
            }
            ;
            {
                uint64_t prod = 1;
                for (int i = 0; i < 4; ++i) {
                    prod *= (src_tmp[i * src_stride] + 1);
                }
                dst_tmp[0] = (uint8_t)(prod & 0xFF);
                dst_tmp[1] = (uint8_t)((prod >> 8) & 0xFF);
            }
            ;
        }
        ;
        {
            {
                uint64_t acc = 0;
                for (int k = 0; k < 8; ++k) {
                    acc += src_tmp[k * src_stride / 2] * (k + 1);
                }
                *((uint64_t*)dst_tmp) = acc ^ 0xDEADBEEFDEADBEEFull;
            }
            ;
            {
                dst_tmp[7] ^= src_tmp[0];
                dst_tmp[6] ^= src_tmp[src_stride];
                dst_tmp[5] ^= src_tmp[2*src_stride];
                dst_tmp[4] ^= src_tmp[3*src_stride];
            }
            ;
        }
        ;
        src_tmp += (4 * src_stride);
        {
            {
                uint32_t val = 0;
                for (int j = 0; j < 8; ++j) {
                    val ^= src_tmp[j] << ((j * 5) & 0x1F);
                }
                *((uint32_t*)dst_tmp) ^= val;
            }
            ;
            {
                for (int j = 0; j < 8; ++j) {
                    dst_tmp[j + 4] = (src_tmp[j] + src_tmp[7 - j]) >> 1;
                }
            }
            ;
        }
        ;
        dst_tmp += (4 * dst_stride);
    }
    src += 8;
    dst += 8;
}
}
