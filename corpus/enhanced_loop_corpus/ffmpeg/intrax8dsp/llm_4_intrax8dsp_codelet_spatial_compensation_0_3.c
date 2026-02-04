#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t zero_prediction_weights[128];
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern uint16_t left_sum[2][8];
extern uint16_t top_sum[2][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; ++y) {
        if (y % 2 == 0) {
            for (x = 0; x < 8; ++x) {
                dst[x] = ((uint32_t)top_sum[0][x] * zero_prediction_weights[y * 16 + x * 2 + 0] + 
                          (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + x * 2 + 1] + 32768) >> 16;
            }
        } else {
            for (x = 0; x < 4; ++x) {
                uint32_t val1 = ((uint32_t)top_sum[0][x] * zero_prediction_weights[y * 16 + x * 2 + 0] + 
                                (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + x * 2 + 1] + 32768) >> 16;
                uint32_t val2 = ((uint32_t)top_sum[0][7 - x] * zero_prediction_weights[y * 16 + (7 - x) * 2 + 0] + 
                                (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + (7 - x) * 2 + 1] + 32768) >> 16;
                dst[x] = val1;
                dst[7 - x] = val2;
            }
        }
        dst += stride;
    }
}
