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
    int32_t *local_tmp = tmp;
    const uint16_t *local_src = src;
    int j;
    for (j = 0; j < h + 5; j++) {
        int32_t val0 = (int32_t)(local_src[0] + local_src[1]) * 20;
        int32_t val1 = (int32_t)(local_src[-1] + local_src[2]) * 5;
        int32_t val2 = (int32_t)(local_src[-2] + local_src[3]);
        local_tmp[0] = val0 - val1 + val2 + pad;

        int32_t val3 = (int32_t)(local_src[1] + local_src[2]) * 20;
        int32_t val4 = (int32_t)(local_src[0] + local_src[3]) * 5;
        int32_t val5 = (int32_t)(local_src[-1] + local_src[4]);
        local_tmp[1] = val3 - val4 + val5 + pad;

        local_tmp += tmpStride;
        local_src += srcStride;
    }
}
