#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h + 5; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 4; j++) {
                int idx = k * 4 + j;
                tmp[idx] = -1 * src1[idx - 2] + -2 * src1[idx - 1] + 96 * src1[idx] + 
                           42 * src1[idx + 1] + -7 * src1[idx + 2] + 0 * src1[idx + 3];
            }
        }
        tmp += 8;
        src1 += srcStride;
    }
}
