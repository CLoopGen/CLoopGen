#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src[];
extern int srcStride[];
extern uint8_t *dst;
extern int dstStride;
extern int srcSliceH;
extern int alpha_first;
extern int width;
extern int x;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (h = 0; h < srcSliceH; h++) {
        uint8_t *dest = dst + dstStride * h;
        uint8_t temp_buffer[4 * 1024]; // Assume max width is 1024 for stack allocation safety
        uint8_t **s = src;
        int stride0 = srcStride[0], stride1 = srcStride[1], stride2 = srcStride[2], stride3 = srcStride[3];
        if (alpha_first) {
            for (x = 0; x < width; x++) {
                temp_buffer[4*x + 0] = s[3][x];
                temp_buffer[4*x + 1] = s[0][x];
                temp_buffer[4*x + 2] = s[1][x];
                temp_buffer[4*x + 3] = s[2][x];
            }
        } else {
            for (x = 0; x < width; x++) {
                temp_buffer[4*x + 0] = s[0][x];
                temp_buffer[4*x + 1] = s[1][x];
                temp_buffer[4*x + 2] = s[2][x];
                temp_buffer[4*x + 3] = s[3][x];
            }
        }
        for (x = 0; x < 4 * width; x++) {
            dest[x] = temp_buffer[x];
        }
        for (i = 0; i < 4; i++)
            src[i] += srcStride[i];
    }
}
