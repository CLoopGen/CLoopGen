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
ptrdiff_t stride = srcStride;
const int coeffs[6] = {0, -1, 5, 5, -1, 0};
for (i = 0; i < h + 5; i++) {
    const uint8_t* baseSrc = src1 - 2;
    for (int j = 0; j < 8; j++) {
        int sum = 0;
        const uint8_t* s = baseSrc + j;
        for (int k = 0; k < 6; k++) {
            sum += coeffs[k] * s[k];
        }
        tmp[j] = sum;
    }
    tmp += 8;
    src1 += stride;
}
}
