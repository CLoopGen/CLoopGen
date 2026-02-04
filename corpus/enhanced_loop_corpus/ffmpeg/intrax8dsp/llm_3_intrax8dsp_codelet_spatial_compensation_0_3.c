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
    // Variant 2: Strided write with transposed accumulation and reversed loop order
    uint8_t *d = dst + (7 * stride); // Start at last row
    uint16_t *w = zero_prediction_weights;
    uint16_t (*ts)[8] = top_sum;
    uint16_t (*ls)[8] = left_sum;

    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 8; x++) {
            // Access weights with same pattern but reverse y affects weight index
            int idx = y * 16 + x * 2;
            d[x] = ((uint32_t)ts[0][x] * w[idx + 0] + 
                    (uint32_t)ls[0][y] * w[idx + 1] + 32768) >> 16;
        }
        d -= stride; // Move upward in memory (negative stride direction)
    }
}
