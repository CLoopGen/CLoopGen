#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern uint8_t *dest;
extern int width;
extern int height;
extern int src1Stride;
extern int src2Stride;
extern int dstStride;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h = 0; h < height; h++) {
    int w;
    if (width >= 16) {
        if (!((((intptr_t)src1) | ((intptr_t)src2) | ((intptr_t)dest)) & 15)) {
            for (w = 0; w < width; w += 16) {
                int chunk;
                for (chunk = 0; chunk < 16 && (w + chunk) < width; chunk++) {
                    int idx = w + chunk;
                    dest[2 * idx + 0] = src1[idx];
                    dest[2 * idx + 1] = src2[idx];
                }
            }
            goto end_loop;
        }
    }
    for (w = 0; w < width; w++) {
        dest[2 * w + 0] = src1[w];
        dest[2 * w + 1] = src2[w];
    }
end_loop:
    dest += dstStride;
    src1 += src1Stride;
    src2 += src2Stride;
}
}
