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
for (i = 0; i < h; i++) {
    int offset = 0;
    for (int j = 0; j < 4; j++) {
        tmp[offset + 0] = 96 * src1[0] + (-1) * src1[-2] + (-2) * src1[-1] + 42 * src1[1] + (-7) * src1[2];
        tmp[offset + 1] = 96 * src1[1] + (-1) * src1[-1] + (-2) * src1[0]  + 42 * src1[2] + (-7) * src1[3];
        tmp[offset + 2] = 96 * src1[2] + (-1) * src1[0]  + (-2) * src1[1]  + 42 * src1[3] + (-7) * src1[4];
        tmp[offset + 3] = 96 * src1[3] + (-1) * src1[1]  + (-2) * src1[2]  + 42 * src1[4] + (-7) * src1[5];

        offset += 4;
        src1 += srcStride / 4;
    }
    tmp += 16;
    src1 += srcStride - (srcStride / 4) * 4; // Adjust back to next full row
}
}
