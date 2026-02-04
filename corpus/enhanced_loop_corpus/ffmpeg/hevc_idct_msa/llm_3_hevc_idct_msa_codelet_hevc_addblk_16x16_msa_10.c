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
    int32_t offset;
    const uint8_t indices[] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60};
    for (loop_cnt = 3; loop_cnt--;) {
        for (int i = 0; i < 16; i++) {
            offset = indices[i];
            dst[i % 4 * stride + i / 4] = (uint8_t)((coeffs[offset] + coeffs[offset + 1] + 1) >> 1);
        }
        ;
        for (int j = 0; j < 4; j++) {
            temp_dst[j * stride] = dst[j * stride];
            temp_dst[j * stride + 1] = dst[j * stride + 1];
        }
        ;
        temp_dst += (4 * stride);
        ;
        for (int j = 0; j < 4; j++) {
            temp_dst[j * stride + 2] = dst[j * stride + 2];
            temp_dst[j * stride + 3] = dst[j * stride + 3];
        }
        ;
        for (int k = 0; k < 4; k++) {
            for (int m = 0; m < 4; m++) {
                coeffs[k * 16 + m] = coeffs[k * 16 + m] < 0 ? 0 : coeffs[k * 16 + m];
            }
        }
        ;
        {
            {
                {
                    coeffs += 16;
                }
                ;
                {
                    coeffs += 16;
                }
                ;
            }
            ;
            {
                {
                    coeffs += 16;
                }
                ;
                {
                    coeffs += 16;
                }
                ;
            }
            ;
        }
        ;
        {
            {
                dst += stride;
            }
            ;
            {
                dst += stride;
            }
            ;
        }
        ;
        {
            {
                dst += stride;
            }
            ;
            {
                dst += stride;
            }
            ;
        }
        ;
        dst += (4 * stride - 4 * stride); // No net change in main dst after adjustments
    }
}
