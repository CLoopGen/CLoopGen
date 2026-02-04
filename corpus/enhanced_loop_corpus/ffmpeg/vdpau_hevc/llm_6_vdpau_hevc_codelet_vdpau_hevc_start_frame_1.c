#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_hevc_diag_scan4x4_x[16];
extern const uint8_t ff_hevc_diag_scan4x4_y[16];
extern const uint8_t ff_hevc_diag_scan8x8_x[64];
extern const uint8_t ff_hevc_diag_scan8x8_y[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (size_t i = 0; i < 6; i++) {
    uint8_t temp_sum_4x4 = 0;
    for (size_t j = 0; j < 16; j++) {
        uint8_t pos = 4 * ff_hevc_diag_scan4x4_y[j] + ff_hevc_diag_scan4x4_x[j];
        temp_sum_4x4 += pos; // Introduce loop-carried dependency (WAW on temp_sum_4x4)
    }
    for (size_t j = 0; j < 64; j++) {
        uint8_t pos = 8 * ff_hevc_diag_scan8x8_y[j] + ff_hevc_diag_scan8x8_x[j];
        if (i < 2) {
            temp_sum_4x4 ^= pos; // Create RAW dependency: use pos computed in this loop
        }
    }
    if (i < 2) {
        temp_sum_4x4 *= 2;
    }
}

}
