#include <stdio.h>

#include <inttypes.h>

extern uint8_t *dst;
extern uint8_t *src;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (dst += len - 1; len > 0; len--, src++, dst--) {
        temp = *src;
        *dst = temp;
    }
}
