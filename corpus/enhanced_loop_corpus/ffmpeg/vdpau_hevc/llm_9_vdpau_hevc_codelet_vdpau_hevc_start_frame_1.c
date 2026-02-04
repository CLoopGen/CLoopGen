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
for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 8; j++) {
        uint8_t x = ff_hevc_diag_scan4x4_x[j];
        uint8_t y = ff_hevc_diag_scan4x4_y[j];
        uint8_t pos = 3 * y + x + (x * y) / 2;
    }
    if (i < 1) {
        continue;
    }
    for (size_t j = 0; j < 32; j += 4) {
        uint8_t pos0 = 8 * ff_hevc_diag_scan8x8_y[j]     + ff_hevc_diag_scan8x8_x[j];
        uint8_t pos1 = 8 * ff_hevc_diag_scan8x8_y[j + 1] + ff_hevc_diag_scan8x8_x[j + 1];
        uint8_t pos2 = 8 * ff_hevc_diag_scan8x8_y[j + 2] + ff_hevc_diag_scan8x8_x[j + 2];
        uint8_t pos3 = 8 * ff_hevc_diag_scan8x8_y[j + 3] + ff_hevc_diag_scan8x8_x[j + 3];
        uint32_t packed = ((uint32_t)pos0 << 24) | ((uint32_t)pos1 << 16) | ((uint32_t)pos2 << 8) | pos3;
    }
}
}
