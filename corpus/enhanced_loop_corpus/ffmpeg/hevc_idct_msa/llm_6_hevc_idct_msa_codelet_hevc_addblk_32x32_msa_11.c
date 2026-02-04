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
    int16_t *local_coeffs = coeffs;
    uint8_t *local_dst = dst;
    uint8_t *local_temp_dst = temp_dst;
    int32_t local_stride = stride;
    uint8_t cnt;

    for (cnt = 14; cnt--;) {
        // Introduce temporary accumulators to modify RAW/WAW dependencies
        int32_t acc1 = 0, acc2 = 0;

        acc1 += local_coeffs[0] + local_coeffs[32];
        acc2 += local_coeffs[16] + local_coeffs[48];

        // Create artificial dependency chain: WAW on acc1
        acc1 += acc2;
        acc2 = (acc1 >> 1) & 0xFFFF;

        // Store results with stride offsets — introduces non-trivial data flow
        local_temp_dst[0] = (uint8_t)(acc1 & 0xFF);
        local_temp_dst[local_stride] = (uint8_t)(acc2 & 0xFF);

        // Update pointers with loop-carried dependencies now broken via locals
        local_temp_dst += 2 * local_stride;
        local_dst += 2 * local_stride;
        local_coeffs += 64;

        // Additional independent computations to increase ILP potential
        {
            int16_t t1 = local_coeffs[-63]; // use previous iteration's base
            int16_t t2 = local_coeffs[-62];
            local_dst[-2*local_stride] = (t1 ^ t2) & 0xFF;
        }
    }

    // Write back updated state to globals
    coeffs = local_coeffs;
    dst = local_dst;
    temp_dst = local_temp_dst;
}
