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
    int16_t *tmp_ptr = tmp;
    uint8_t *src_ptr = src;
    for (i = 0; i < h + 5; i++) {
        int offset = i * tmpStride;
        int src_offset = i * srcStride;
        tmp_ptr[offset] = (src_ptr[src_offset] + src_ptr[src_offset + 1]) * 20 
                        - (src_ptr[src_offset - 1] + src_ptr[src_offset + 2]) * 5 
                        + (src_ptr[src_offset - 2] + src_ptr[src_offset + 3]) + pad;
        tmp_ptr[offset + 1] = (src_ptr[src_offset + 1] + src_ptr[src_offset + 2]) * 20 
                            - (src_ptr[src_offset] + src_ptr[src_offset + 3]) * 5 
                            + (src_ptr[src_offset - 1] + src_ptr[src_offset + 4]) + pad;
    }
}
