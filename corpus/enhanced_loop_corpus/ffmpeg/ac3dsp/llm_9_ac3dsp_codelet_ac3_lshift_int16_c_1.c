#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned int shift;
extern uint32_t *src32;
extern  uint32_t mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        src32[i] = ((src32[i] << shift) & mask) ^ ((src32[i] >> (32 - shift)) & ~mask);
        src32[i] = (src32[i] + (src32[i] << 1)) & mask;
    }
}
