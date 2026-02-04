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
        for (int j = 0; j < 8; j++) {
            tmp[j] = -1 * src1[j - 2] + -2 * src1[j - 1] + 96 * src1[j] + 
                     42 * src1[j + 1] + -7 * src1[j + 2] + 0 * src1[j + 3];
        }
        tmp += 8;
        src1 += srcStride;
    }
}
