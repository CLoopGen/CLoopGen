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
    int j;
    for (j = 0; j < 8; j++) {
        int offset = j + 2;
        tmp[j] = 
            (-1) * src1[offset - 1] + 
             5  * src1[offset + 0] + 
             5  * src1[offset + 1] + 
            (-1) * src1[offset + 2];
    }
    tmp += 8;
    src1 += srcStride;
}
}
