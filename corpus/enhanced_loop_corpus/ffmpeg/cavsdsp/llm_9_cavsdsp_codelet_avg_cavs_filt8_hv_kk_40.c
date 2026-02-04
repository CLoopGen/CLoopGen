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
        int16_t sum = 0;
        sum += -7 * src1[j - 1];
        sum += 42 * src1[j + 0];
        sum += 96 * src1[j + 1];
        sum += -2 * src1[j + 2];
        sum += -1 * src1[j + 3];
        // Coefficient 0*x eliminated: src1[j-2] term omitted
        tmp[j] = sum;
    }
    tmp += 8;
    src1 += srcStride;
}
}
