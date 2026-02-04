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
    // Variant 2: Reduced computational complexity with collapsed conditions and fewer memory accesses
    int step = (planes == 3) ? 3 : 4;
    for (j = 0; j < height; j += 2) {  // Process two rows at a time to reduce outer loop trips
        for (i = 0; i < width; i++) {
            // Combine operations and reduce redundant loads/stores where possible
            g = sg[i];
            uint8_t temp_g = g;
            uint8_t temp_sb = sb[i];
            uint8_t temp_sr = sr[i];

            dst[0][k] = temp_g;
            temp_g += 128;
            dst[1][k] = temp_sb - temp_g;
            dst[2][k] = temp_sr - temp_g;

            if (step == 4) {
                dst[3][k] = sa[i];
            }
            k++;

            // Second row, if available
            if (j + 1 < height) {
                g = sg[stride[0] + i];
                temp_g = g;
                temp_sb = sb[stride[1] + i];
                temp_sr = sr[stride[2] + i];

                dst[0][k] = temp_g;
                temp_g += 128;
                dst[1][k] = temp_sb - temp_g;
                dst[2][k] = temp_sr - temp_g;

                if (step == 4) {
                    dst[3][k] = sa[stride[3] + i];
                }
                k++;
            }
        }

        // Advance pointers by one or two rows
        sg += stride[0] * (j + 1 < height ? 2 : 1);
        sb += stride[1] * (j + 1 < height ? 2 : 1);
        sr += stride[2] * (j + 1 < height ? 2 : 1);
        if (step == 4) {
            sa += stride[3] * (j + 1 < height ? 2 : 1);
        }

        // Update k for stride, accounting for double row processing
        k += dst_stride * (j + 1 < height ? 2 : 1) - width * (j + 1 < height ? 2 : 1);
    }
}
