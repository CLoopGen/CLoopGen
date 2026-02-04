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
for (i = 0; i < len; i++)
    dst[i * dst_step] = src[i * src_step];

}
