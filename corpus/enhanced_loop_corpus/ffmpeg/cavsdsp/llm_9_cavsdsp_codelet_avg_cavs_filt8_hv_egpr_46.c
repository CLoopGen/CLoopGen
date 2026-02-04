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
        tmp[offset]     = -1 * src1[j - 1] + 5 * src1[j] + 5 * src1[j + 1] - 1 * src1[j + 2];
        tmp[offset + 1] = -1 * src1[j + 0] + 5 * src1[j + 1] + 5 * src1[j + 2] - 1 * src1[j + 3];
        offset += 2;
    }
    tmp += 8;
    src1 += srcStride;
}
}
