#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t accumulator = 0;
    for (loop_count = (height >> 2); loop_count--;) {
        accumulator ^= src[0];          
        dst[0] = accumulator;             

        accumulator ^= src[src_stride];   
        dst[dst_stride] = accumulator;    

        accumulator ^= src[2 * src_stride]; 
        dst[2 * dst_stride] = accumulator;  

        accumulator ^= src[3 * src_stride]; 
        dst[3 * dst_stride] = accumulator;  

        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
