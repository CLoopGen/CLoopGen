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
    int32_t *tmp_ptr = tmp;
    uint16_t *src_ptr = src;
    for (i = 0; i < h + 5; i++) {
        int32_t val0 = (int32_t)(src_ptr[0] + src_ptr[1]) * 20 - 
                       (src_ptr[-1] + src_ptr[2]) * 5 + 
                       (src_ptr[-2] + src_ptr[3]) + pad;
        int32_t val1 = (int32_t)(src_ptr[1] + src_ptr[2]) * 20 - 
                       (src_ptr[0] + src_ptr[3]) * 5 + 
                       (src_ptr[-1] + src_ptr[4]) + pad;

        tmp_ptr[0] = val0;
        tmp_ptr[1] = val1;

        tmp_ptr += tmpStride;
        src_ptr += srcStride;
    }
}
