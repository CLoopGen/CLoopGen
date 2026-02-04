#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern  uint8_t *src;
extern int src_step;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = dst_step * src_step;
    for (i = 0; i < len * stride; i += stride) {
        dst[i / src_step] = src[i / dst_step];
    }
}
