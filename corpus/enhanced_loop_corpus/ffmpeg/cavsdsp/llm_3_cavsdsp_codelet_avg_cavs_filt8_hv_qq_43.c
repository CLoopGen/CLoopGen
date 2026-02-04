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
    const uint8_t *s = src1;
    int16_t temp[8];
    for (int j = 0; j < 8; j++) {
        int offset = j - 2;
        temp[j] = 0 * s[offset - 0] + (-1) * s[offset + 1] + 5 * s[offset + 2] + 
                  5 * s[offset + 3] + (-1) * s[offset + 4] + 0 * s[offset + 5];
    }
    for (int j = 0; j < 8; j++) {
        tmp[j] = temp[j];
    }
    tmp += 8;
    src1 += srcStride;
}
}
