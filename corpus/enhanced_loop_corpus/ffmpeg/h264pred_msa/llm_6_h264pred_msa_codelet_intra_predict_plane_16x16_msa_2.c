#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern uint8_t lpcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp1, temp2;
    for (lpcnt = 8; lpcnt--;) {
        temp1 = src[0];
        temp2 = src[stride];
        src[stride * 2] = temp1 + temp2;
        temp1 = src[stride * 2] ^ temp1;
        src[0] = temp1;
        src += 2 * stride;
    }
}
