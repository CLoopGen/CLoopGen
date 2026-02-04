#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int srcHeight;
extern int srcStride;
extern int dstStride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < srcHeight; y++) {
    const int mmxSize = 1;
    uint8_t s0 = src[0];
    uint8_t s1 = src[srcStride];
    dst[0] = (s0 * 3 + s1) >> 2;
    dst[dstStride] = (s0 + 3 * s1) >> 2;

    for (x = mmxSize - 1; x < srcWidth - 1; x++) {
        uint8_t left = src[x];
        uint8_t right = src[x + 1];
        uint8_t down_left = src[x + srcStride];
        uint8_t down_right = src[x + srcStride + 1];

        uint8_t val1 = (left * 3 + down_right) >> 2;
        uint8_t val2 = (left + 3 * down_right) >> 2;
        uint8_t val3 = (right + 3 * down_left) >> 2;
        uint8_t val4 = (right * 3 + down_left) >> 2;

        dst[2 * x + 1] = val1;
        dst[2 * x + dstStride + 2] = val2;
        dst[2 * x + dstStride + 1] = val3;
        dst[2 * x + 2] = val4;
    }

    uint8_t edge_cur = src[srcWidth - 1];
    uint8_t edge_down = src[srcWidth - 1 + srcStride];
    uint8_t edge_val1 = (edge_cur * 3 + edge_down) >> 2;
    uint8_t edge_val2 = (edge_cur + 3 * edge_down) >> 2;
    dst[srcWidth * 2 - 1] = edge_val1;
    dst[srcWidth * 2 - 1 + dstStride] = edge_val2;

    dst += dstStride * 2;
    src += srcStride;
}
}
