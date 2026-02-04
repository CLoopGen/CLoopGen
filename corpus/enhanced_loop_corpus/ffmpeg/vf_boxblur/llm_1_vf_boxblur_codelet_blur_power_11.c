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
if (len > 0) {
    for (i = 0; i < len; i += 2) {
        *(uint16_t *)(dst + i * dst_step) = *(uint16_t *)(src + i * src_step);
        if (i + 1 < len) {
            *(uint16_t *)(dst + (i + 1) * dst_step) = *(uint16_t *)(src + (i + 1) * src_step);
        }
    }
}
}
