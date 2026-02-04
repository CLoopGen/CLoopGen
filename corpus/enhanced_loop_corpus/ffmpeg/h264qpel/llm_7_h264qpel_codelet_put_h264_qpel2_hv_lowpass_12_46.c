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
int32_t prev_tmp0 = 0;
for (i = 0; i < h + 5; i++) {
    tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad + prev_tmp0;
    tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
    prev_tmp0 = tmp[0];
    tmp += tmpStride;
    src += srcStride;
}
}
