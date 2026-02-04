#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern uint8_t *alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_src, temp_dst, temp_alpha;
    for (i = 0; i < size; i++) {
        temp_src = src[i];
        temp_dst = dst[i];
        temp_alpha = alpha[i];
        dst[i] += ((temp_src - temp_dst) * temp_alpha) >> 8;
    }
}
