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
int16_t prev_tmp_val = 0;
for (i = 0; i < h + 5; i++) {
    int16_t val0 = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad + prev_tmp_val;
    int16_t val1 = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
    tmp[0] = val0;
    tmp[1] = val1;
    prev_tmp_val = val0; // Introduce WAW and loop-carried dependency
    tmp += tmpStride;
    src += srcStride;
}
}
