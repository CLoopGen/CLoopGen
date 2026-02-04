#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern uint8_t lpcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (lpcnt = 16; lpcnt--;) {
        uint8_t temp1 = src[0];
        uint8_t temp2 = src[stride];
        uint8_t temp3 = src[2*stride];
        uint8_t temp4 = src[3*stride];
        
        temp1 ^= temp2;
        temp3 ^= temp4;
        temp1 += temp3;
        
        src[0] = temp1;
        src[2*stride] = temp3;
        
        src += stride;
    }
}
