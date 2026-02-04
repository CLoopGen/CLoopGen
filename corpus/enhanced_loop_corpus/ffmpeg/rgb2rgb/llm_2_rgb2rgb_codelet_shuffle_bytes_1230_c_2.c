#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size; i += 4) {
        int base_dst = i;
        int base_src = i;
        dst[base_dst + 0] = src[base_src + 1];
        dst[base_dst + 1] = src[base_src + 2];
        dst[base_dst + 2] = src[base_src + 3];
        dst[base_dst + 3] = src[base_src + 0];
    }
}
