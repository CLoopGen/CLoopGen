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
    uint32_t acc;
    for (y = 0; y < 8; y++) {
        acc = left_sum[0][y]; // Introduce loop-carried dependency on accumulator conceptually reused (though not across iterations here, data flow is modified)
        for (x = 0; x < 8; x++) {
            uint32_t top_contrib = (uint32_t)top_sum[0][x] * zero_prediction_weights[y * 16 + x * 2 + 0];
            uint32_t left_contrib = acc * zero_prediction_weights[y * 16 + x * 2 + 1];
            dst[x] = (top_contrib + left_contrib + 32768) >> 16;
        }
        dst += stride;
    }
}
