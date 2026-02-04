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
const int coeffs[6] = {0, -1, 5, 5, -1, 0};
const int offsets[8] = {-2, -1, 0, 1, 2, 3, 4, 5};
for (i = 0; i < h + 5; i++) {
    for (int j = 0; j < 8; j++) {
        tmp[j] = 0;
        for (int k = 0; k < 6; k++) {
            tmp[j] += coeffs[k] * src1[offsets[j] + k];
        }
    }
    tmp += 8;
    src1 += srcStride;
}
}
