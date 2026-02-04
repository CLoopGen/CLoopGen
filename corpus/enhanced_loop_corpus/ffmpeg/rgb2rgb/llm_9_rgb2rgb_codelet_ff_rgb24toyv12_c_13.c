#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *ydst;
extern uint8_t *udst;
extern uint8_t *vdst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int srcStride;
extern int32_t ry;
extern int32_t gy;
extern int32_t by;
extern int32_t ru;
extern int32_t gu;
extern int32_t bu;
extern int32_t rv;
extern int32_t gv;
extern int32_t bv;
extern int y;
extern  int chromWidth;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 4) {
    int i;
    for (i = 0; i < chromWidth; i++) {
        // Process four rows of luma and two of chroma to increase computational density
        const int offsets[4] = {0, srcStride, 2*srcStride, 3*srcStride};
        for (int row = 0; row < 4 && (y + row) < height; row++) {
            unsigned int b = src[offsets[row] + 6 * i + 0];
            unsigned int g = src[offsets[row] + 6 * i + 1];
            unsigned int r = src[offsets[row] + 6 * i + 2];
            unsigned int Y = ((ry * r + gy * g + by * b) >> 15) + 16;
            ydst[row * lumStride + 2 * i] = Y;

            b = src[offsets[row] + 6 * i + 3];
            g = src[offsets[row] + 6 * i + 4];
            r = src[offsets[row] + 6 * i + 5];
            Y = ((ry * r + gy * g + by * b) >> 15) + 16;
            ydst[row * lumStride + 2 * i + 1] = Y;
        }

        // Chroma is updated only once per 2x2 block (at even y)
        if (y + 1 < height) {
            unsigned int b = src[6 * i + 0];
            unsigned int g = src[6 * i + 1];
            unsigned int r = src[6 * i + 2];
            unsigned int U = ((ru * r + gu * g + bu * b) >> 15) + 128;
            unsigned int V = ((rv * r + gv * g + bv * b) >> 15) + 128;
            udst[i] = U;
            vdst[i] = V;
        }
    }

    // Advance pointers
    ydst += 4 * lumStride;
    src += 4 * srcStride;
    if (y + 1 < height) {
        udst += chromStride;
        vdst += chromStride;
    }
}
}
