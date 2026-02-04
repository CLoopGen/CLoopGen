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
const uint16_t *src_ptr = src;
int32_t *tmp_ptr = tmp;
ptrdiff_t src_step = srcStride;
ptrdiff_t tmp_step = tmpStride;
for (i = 0; i < h + 5; i++) {
    tmp_ptr[0] = (src_ptr[0] + src_ptr[src_step]) * 20 - (src_ptr[-src_step] + src_ptr[2*src_step]) * 5 + (src_ptr[-2*src_step] + src_ptr[3*src_step]) + pad;
    tmp_ptr[1] = (src_ptr[src_step] + src_ptr[2*src_step]) * 20 - (src_ptr[0] + src_ptr[3*src_step]) * 5 + (src_ptr[-src_step] + src_ptr[4*src_step]) + pad;
    tmp_ptr += tmp_step;
    src_ptr += src_step;
}
}
