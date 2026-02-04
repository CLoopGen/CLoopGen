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
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    const ptrdiff_t offset_array[] = {0,1,-1,2,-2,3,4,5,6,7,8,9,10};
    tmp[0] = (src[offset_array[0]] + src[offset_array[1]]) * 20 - (src[offset_array[2]] + src[offset_array[3]]) * 5 + (src[offset_array[4]] + src[offset_array[5]]) + pad;
    tmp[1] = (src[offset_array[1]] + src[offset_array[3]]) * 20 - (src[offset_array[0]] + src[offset_array[5]]) * 5 + (src[offset_array[2]] + src[offset_array[6]]) + pad;
    tmp[2] = (src[offset_array[3]] + src[offset_array[5]]) * 20 - (src[offset_array[1]] + src[offset_array[6]]) * 5 + (src[offset_array[0]] + src[offset_array[7]]) + pad;
    tmp[3] = (src[offset_array[5]] + src[offset_array[6]]) * 20 - (src[offset_array[3]] + src[offset_array[7]]) * 5 + (src[offset_array[1]] + src[offset_array[8]]) + pad;
    tmp[4] = (src[offset_array[6]] + src[offset_array[7]]) * 20 - (src[offset_array[5]] + src[offset_array[8]]) * 5 + (src[offset_array[2]] + src[offset_array[9]]) + pad;
    tmp[5] = (src[offset_array[7]] + src[offset_array[8]]) * 20 - (src[offset_array[6]] + src[offset_array[9]]) * 5 + (src[offset_array[3]] + src[offset_array[10]]) + pad;
    tmp[6] = (src[offset_array[8]] + src[offset_array[9]]) * 20 - (src[offset_array[7]] + src[offset_array[10]]) * 5 + (src[offset_array[4]] + src[9+2]) + pad;
    tmp[7] = (src[offset_array[9]] + src[8+2]) * 20 - (src[offset_array[8]] + src[9+2]) * 5 + (src[offset_array[5]] + src[10+2]) + pad;
    tmp += tmpStride;
    src += srcStride;
}
}
