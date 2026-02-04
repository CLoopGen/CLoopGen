#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t stride;
extern uint8_t lpcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (lpcnt = 4; lpcnt--;) {
        for (int i = 0; i < 3; i++) {
            {
                {
                    src[stride] += src[0] * 2;
                    src[2*stride] ^= src[stride] + 1;
                }
            }
            src += stride;
        }
        {
            src -= stride / 2;
        }
        {
            src[0] = (src[0] + src[stride]) & 0x7F;
        }
        src += 3 * stride;
    }
}
