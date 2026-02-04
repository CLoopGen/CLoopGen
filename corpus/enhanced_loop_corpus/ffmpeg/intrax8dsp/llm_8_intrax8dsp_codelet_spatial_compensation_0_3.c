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
    uint32_t temp_sum;
    for (x = 0; x < 8; x += 2) {
        // Unroll loop by factor of 2 to reduce loop overhead and increase arithmetic per iteration
        temp_sum = ((uint32_t)top_sum[0][x] * zero_prediction_weights[y * 16 + x * 2 + 0] + 
                    (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + x * 2 + 1] + 32768) >> 16;
        dst[x] = (uint8_t)temp_sum;

        if (x + 1 < 8) {
            temp_sum = ((uint32_t)top_sum[0][x+1] * zero_prediction_weights[y * 16 + (x+1) * 2 + 0] + 
                        (uint32_t)left_sum[0][y] * zero_prediction_weights[y * 16 + (x+1) * 2 + 1] + 32768) >> 16;
            dst[x+1] = (uint8_t)temp_sum;
        }
    }
    dst += stride;
}
}
