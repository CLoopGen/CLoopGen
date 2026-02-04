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
        int srcIdx = j - 2;
        tmp[j] = 0 * src1[srcIdx + 0] + 
                -1 * src1[srcIdx + 1] + 
                 5 * src1[srcIdx + 2] + 
                 5 * src1[srcIdx + 3] + 
                -1 * src1[srcIdx + 4] + 
                 0 * src1[srcIdx + 5];
    }
    tmp += 8;
    src1 += srcStride;
}
}
