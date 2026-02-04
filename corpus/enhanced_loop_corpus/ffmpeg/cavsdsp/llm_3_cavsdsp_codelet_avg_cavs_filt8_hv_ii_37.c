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
        int base = offset - 2;
        tmp[j] = 
            -1 * src1[base + 0] + 
            -2 * src1[base + 1] + 
            96 * src1[base + 2] + 
            42 * src1[base + 3] + 
            -7 * src1[base + 4] + 
            0  * src1[base + 5];
        offset++;
    }
    tmp += 8;
    src1 += srcStride;
}
}
