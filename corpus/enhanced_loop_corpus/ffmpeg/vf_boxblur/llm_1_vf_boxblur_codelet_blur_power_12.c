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
    int outer = len / 2;
    int remainder = len % 2;
    int i;

    for (i = 0; i < outer; i++) {
        dst[i * 2 * dst_step] = src[i * 2 * src_step];
        dst[i * 2 * dst_step + dst_step] = src[i * 2 * src_step + src_step];
    }

    if (remainder) {
        dst[(len - 1) * dst_step] = src[(len - 1) * src_step];
    }
}
