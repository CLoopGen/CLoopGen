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
    for (y = 0; y < 8; y++) {
        dst[y * stride] = ((uint32_t)top_sum[0][0] * zero_prediction_weights[y * 16 + 0] + (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + 1] + 32768) >> 16;
        dst[y * stride + 1] = ((uint32_t)top_sum[0][1] * zero_prediction_weights[y * 16 + 2] + (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + 3] + 32768) >> 16;
        dst[y * stride + 2] = ((uint32_t)top_sum[0][2] * zero_prediction_weights[y * 16 + 4] + (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + 5] + 32768) >> 16;
        dst[y * stride + 3] = ((uint32_t)top_sum[0][3] * zero_prediction_weights[y * 16 + 6] + (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + 7] + 32768) >> 16;
        dst[y * stride + 4] = ((uint32_t)top_sum[0][4] * zero_prediction_weights[y * 16 + 8] + (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + 9] + 32768) >> 16;
        dst[y * stride + 5] = ((uint32_t)top_sum[0][5] * zero_prediction_weights[y * 16 + 10] + (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + 11] + 32768) >> 16;
        dst[y * stride + 6] = ((uint32_t)top_sum[0][6] * zero_prediction_weights[y * 16 + 12] + (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + 13] + 32768) >> 16;
        dst[y * stride + 7] = ((uint32_t)top_sum[0][7] * zero_prediction_weights[y * 16 + 14] + (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + 15] + 32768) >> 16;
    }
}
