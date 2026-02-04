#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size; i += 2) {
        uint8_t temp1 = src[i + 0] ^ 0xFF;
        uint8_t temp2 = src[i + 1] ^ 0xFF;
        dst[i + 0] = (i + 1 < src_size) ? temp2 : temp1;
        dst[i + 1] = temp1;
    }
}
