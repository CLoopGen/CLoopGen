#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern uint8_t *dst;
extern int32_t stride;
extern uint8_t loop_cnt;
extern uint8_t *temp_dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 3; loop_cnt--;) {
        {
            {
                dst[0] = coeffs[0] > 0 ? (uint8_t)coeffs[0] : 0;
                dst[stride] = coeffs[16] > 0 ? (uint8_t)coeffs[16] : 0;
                dst[2*stride] = coeffs[32] > 0 ? (uint8_t)coeffs[32] : 0;
                dst[3*stride] = coeffs[48] > 0 ? (uint8_t)coeffs[48] : 0;
            }
        }
        ;
        {
            {
                dst[1] = coeffs[1] > 0 ? (uint8_t)coeffs[1] : 0;
                dst[1 + stride] = coeffs[17] > 0 ? (uint8_t)coeffs[17] : 0;
                dst[1 + 2*stride] = coeffs[33] > 0 ? (uint8_t)coeffs[33] : 0;
                dst[1 + 3*stride] = coeffs[49] > 0 ? (uint8_t)coeffs[49] : 0;
            }
        }
        ;
        {
            {
                dst[2] = coeffs[2] > 0 ? (uint8_t)coeffs[2] : 0;
                dst[2 + stride] = coeffs[18] > 0 ? (uint8_t)coeffs[18] : 0;
                dst[2 + 2*stride] = coeffs[34] > 0 ? (uint8_t)coeffs[34] : 0;
                dst[2 + 3*stride] = coeffs[50] > 0 ? (uint8_t)coeffs[50] : 0;
            }
        }
        ;
        {
            {
                dst[3] = coeffs[3] > 0 ? (uint8_t)coeffs[3] : 0;
                dst[3 + stride] = coeffs[19] > 0 ? (uint8_t)coeffs[19] : 0;
                dst[3 + 2*stride] = coeffs[35] > 0 ? (uint8_t)coeffs[35] : 0;
                dst[3 + 3*stride] = coeffs[51] > 0 ? (uint8_t)coeffs[51] : 0;
            }
        }
        ;
        {
            {
                temp_dst[0] = dst[0];
                temp_dst[stride] = dst[stride];
            }
            ;
            {
                temp_dst[2*stride] = dst[2*stride];
                temp_dst[3*stride] = dst[3*stride];
            }
        }
        ;
        temp_dst += (4 * stride);
        {
            {
                temp_dst[1] = dst[1];
                temp_dst[1 + stride] = dst[1 + stride];
            }
            ;
            {
                temp_dst[1 + 2*stride] = dst[1 + 2*stride];
                temp_dst[1 + 3*stride] = dst[1 + 3*stride];
            }
        }
        ;
        {
            {
                temp_dst[2] = dst[2];
                temp_dst[2 + stride] = dst[2 + stride];
            }
            ;
            {
                temp_dst[2 + 2*stride] = dst[2 + 2*stride];
                temp_dst[2 + 3*stride] = dst[2 + 3*stride];
            }
        }
        ;
        coeffs += 64;
        {
            {
                {
                    dst += 1;
                }
                ;
                {
                    temp_dst += 1;
                }
                ;
            }
            ;
            {
                {
                    dst += 1;
                }
                ;
                {
                    temp_dst += 1;
                }
                ;
            }
            ;
        }
        ;
        {
            {
                {
                    dst += 1;
                }
                ;
                {
                    temp_dst += 1;
                }
                ;
            }
            ;
            {
                {
                    dst += 1;
                }
                ;
                {
                    temp_dst += 1;
                }
                ;
            }
            ;
        }
        ;
        {
            {
                coeffs -= 4;
            }
            ;
            {
                coeffs -= 4;
            }
            ;
        }
        ;
        {
            {
                coeffs -= 4;
            }
            ;
            {
                coeffs -= 4;
            }
            ;
        }
        ;
        dst += (4 * stride - 4);
        temp_dst += (4 * stride - 4);
    }
}
