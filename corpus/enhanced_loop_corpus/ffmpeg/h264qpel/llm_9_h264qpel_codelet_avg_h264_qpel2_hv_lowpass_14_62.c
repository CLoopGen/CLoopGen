#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int32_t t0 = (src[0] + src[1]) * 20;
    int32_t t1 = (src[-1] + src[2]) * 5;
    int32_t t2 = (src[-2] + src[3]);
    tmp[0] = t0 - t1 + t2 + pad;
    tmp[1] = t0 - t1 + t2 + pad; // Reuse intermediate values for higher intensity
    tmp[2] = t0 - t1 + t2 + pad;
    tmp[3] = t0 - t1 + t2 + pad;
    tmp += tmpStride;
    src += srcStride;
}
}
