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
    uint16_t temp_sum[8];
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            temp_sum[x] = ((uint32_t)top_sum[0][x] * zero_prediction_weights[y * 16 + x * 2 + 0] +
                          (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + x * 2 + 1] + 32768) >> 16;
        }
        for (x = 0; x < 8; x++) {
            dst[x] = temp_sum[x];
        }
        dst += stride;
    }
}
