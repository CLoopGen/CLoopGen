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
for (i = 0; i < h + 3; i++) {
    int16_t val0 = (src[0] + src[1]) * 15 - (src[-1] + src[2]) * 3 + pad;
    int16_t val1 = (src[1] + src[2]) * 15 - (src[0] + src[3]) * 3 + pad;
    tmp[0] = val0;
    tmp[1] = val1;
    tmp += tmpStride;
    src += srcStride;
}
}
