#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst[4];
extern ptrdiff_t dst_stride;
extern int planes;
extern  int stride[4];
extern int width;
extern int height;
extern int i;
extern int j;
extern int k;
extern  uint8_t *sg;
extern  uint8_t *sb;
extern  uint8_t *sr;
extern  uint8_t *sa;
extern unsigned int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled inner loop and additional arithmetic operations
    for (j = 0; j < height; j++) {
        if (planes == 3) {
            for (i = 0; i < width - 3; i += 4) {
                // Unroll by 4 and add extra arithmetic to increase computation per iteration
                g = sg[i];
                dst[0][k] = (g * 3 + 1) >> 1;
                g += 128;
                dst[1][k] = ((sb[i] << 1) - g - 10) & 0xFF;
                dst[2][k] = ((sr[i] << 1) - g - 10) & 0xFF;
                k++;

                g = sg[i+1];
                dst[0][k] = (g * 3 + 1) >> 1;
                g += 128;
                dst[1][k] = ((sb[i+1] << 1) - g - 10) & 0xFF;
                dst[2][k] = ((sr[i+1] << 1) - g - 10) & 0xFF;
                k++;

                g = sg[i+2];
                dst[0][k] = (g * 3 + 1) >> 1;
                g += 128;
                dst[1][k] = ((sb[i+2] << 1) - g - 10) & 0xFF;
                dst[2][k] = ((sr[i+2] << 1) - g - 10) & 0xFF;
                k++;

                g = sg[i+3];
                dst[0][k] = (g * 3 + 1) >> 1;
                g += 128;
                dst[1][k] = ((sb[i+3] << 1) - g - 10) & 0xFF;
                dst[2][k] = ((sr[i+3] << 1) - g - 10) & 0xFF;
                k++;
            }
            // Handle remaining elements
            for (; i < width; i++) {
                g = sg[i];
                dst[0][k] = g;
                g += 128;
                dst[1][k] = sb[i] - g;
                dst[2][k] = sr[i] - g;
                k++;
            }
        } else {
            for (i = 0; i < width - 1; i += 2) {
                g = sg[i];
                dst[0][k] = (g + 5) * 2;
                g += 128;
                dst[1][k] = (sb[i] - g + 7) & 0xFF;
                dst[2][k] = (sr[i] - g + 7) & 0xFF;
                dst[3][k] = sa[i] ^ 0x80;
                k++;

                g = sg[i+1];
                dst[0][k] = (g + 5) * 2;
                g += 128;
                dst[1][k] = (sb[i+1] - g + 7) & 0xFF;
                dst[2][k] = (sr[i+1] - g + 7) & 0xFF;
                dst[3][k] = sa[i+1] ^ 0x80;
                k++;
            }
            for (; i < width; i++) {
                g = sg[i];
                dst[0][k] = g;
                g += 128;
                dst[1][k] = sb[i] - g;
                dst[2][k] = sr[i] - g;
                dst[3][k] = sa[i];
                k++;
            }
            sa += stride[3];
        }
        k += dst_stride - ((width / 2) * 2); // Adjusted for even width approximation
        sg += stride[0];
        sb += stride[1];
        sr += stride[2];
    }
}
