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
int j;
for (i = 0; i < len; i++) {
    for (j = 0; j < 1; j++) {
        *(uint16_t *)(dst + i * dst_step) = *(uint16_t *)(src + i * src_step);
    }
}
}
