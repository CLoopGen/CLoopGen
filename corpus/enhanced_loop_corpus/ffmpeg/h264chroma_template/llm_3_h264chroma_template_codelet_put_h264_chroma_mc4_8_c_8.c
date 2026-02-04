#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *dst_temp = dst;
    uint8_t *src_temp = src;
    for (i = 0; i < h; i++) {
        *(dst_temp++) = (((A * *(src_temp++)) + 32) >> 6);
        *(dst_temp++) = (((A * *(src_temp++)) + 32) >> 6);
        *(dst_temp++) = (((A * *(src_temp++)) + 32) >> 6);
        *(dst_temp++) = (((A * *(src_temp++)) + 32) >> 6);
        dst_temp += (stride - 4);
        src_temp += (stride - 4);
    }
}
