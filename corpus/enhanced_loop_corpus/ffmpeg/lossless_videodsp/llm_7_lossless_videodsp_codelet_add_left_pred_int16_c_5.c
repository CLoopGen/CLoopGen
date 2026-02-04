#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern ptrdiff_t w;
extern unsigned int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_acc = acc;
    for (; i < w; i++) {
        local_acc += src[i];
        dst[i] = local_acc & mask;
    }
    acc = local_acc;
}
