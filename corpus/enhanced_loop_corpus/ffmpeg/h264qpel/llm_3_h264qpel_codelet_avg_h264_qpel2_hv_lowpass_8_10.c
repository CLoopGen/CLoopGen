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
    ptrdiff_t *index_map = (ptrdiff_t*)alloca((h + 5) * sizeof(ptrdiff_t));
    for (int j = 0; j < h + 5; j++) {
        index_map[j] = j;
    }

    for (i = 0; i < h + 5; i++) {
        ptrdiff_t idx = index_map[i];
        int16_t *tmp_addr = tmp + idx * tmpStride;
        uint8_t *src_addr = src + idx * srcStride;

        tmp_addr[0] = (src_addr[0] + src_addr[1]) * 20 - (src_addr[-1] + src_addr[2]) * 5 + (src_addr[-2] + src_addr[3]) + pad;
        tmp_addr[1] = (src_addr[1] + src_addr[2]) * 20 - (src_addr[0] + src_addr[3]) * 5 + (src_addr[-1] + src_addr[4]) + pad;
    }
}
