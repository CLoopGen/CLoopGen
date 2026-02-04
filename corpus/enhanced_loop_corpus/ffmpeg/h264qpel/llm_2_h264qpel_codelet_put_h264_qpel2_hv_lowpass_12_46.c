#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    int offset = i * srcStride;
    tmp[0] = (src[offset] + src[offset + 1]) * 20 - (src[offset - 1] + src[offset + 2]) * 5 + (src[offset - 2] + src[offset + 3]) + pad;
    tmp[1] = (src[offset + 1] + src[offset + 2]) * 20 - (src[offset] + src[offset + 3]) * 5 + (src[offset - 1] + src[offset + 4]) + pad;
    tmp += tmpStride;
}
}
