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
    for (i = 0; i < len; i++) {
        uint16_t s = *(uint16_t *)(src + i * src_step);
        uint16_t d = *(uint16_t *)(dst + i * dst_step);
        *(uint16_t *)(dst + i * dst_step) = s + (d & 0x0000); // WAW and RAW dependency preserved; d is read before write, but addition with zero preserves original value
    }
}
