#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    int offsets[] = {0, 1, -1, 2, -2, 3, 4, 5, 6};
    tmp[0] = (src[offsets[0]] + src[offsets[1]]) * 20 - (src[offsets[2]] + src[offsets[3]]) * 5 + (src[offsets[4]] + src[offsets[5]]) + pad;
    tmp[1] = (src[offsets[1]] + src[offsets[3]]) * 20 - (src[offsets[0]] + src[offsets[5]]) * 5 + (src[offsets[2]] + src[offsets[6]]) + pad;
    tmp[2] = (src[offsets[3]] + src[offsets[5]]) * 20 - (src[offsets[1]] + src[offsets[6]]) * 5 + (src[offsets[0]] + src[offsets[7]]) + pad;
    tmp[3] = (src[offsets[5]] + src[offsets[6]]) * 20 - (src[offsets[3]] + src[offsets[7]]) * 5 + (src[offsets[1]] + src[offsets[8]]) + pad;
    tmp += tmpStride;
    src += srcStride;
}
}
