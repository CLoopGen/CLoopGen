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
    const ptrdiff_t indices[] = {0, 1, 2, 3, 4, 5, 6, 7};
    for (int j = 0; j < 8; j++) {
        int idx = indices[j];
        tmp[idx] = (src[idx] + src[idx+1]) * 20 - (src[idx-1] + src[idx+2]) * 5 + (src[idx-2] + src[idx+3]) + pad;
    }
    tmp += tmpStride;
    src += srcStride;
}
}
