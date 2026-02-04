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
    int offset = 0;
    for (int j = 0; j < 8; j++) {
        tmp[j] = 0 * src1[offset - 2] + -7 * src1[offset - 1] + 42 * src1[offset] +
                 96 * src1[offset + 1] + -2 * src1[offset + 2] + -1 * src1[offset + 3];
        offset++;
    }
    tmp += 8;
    src1 += srcStride;
}
}
