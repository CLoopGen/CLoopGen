#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int x;
extern int unaligned_w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < unaligned_w; x++) {
        uint8_t val1 = *src1++;
        uint8_t val2 = *src2++;
        if (val1 >= val2) {
            *dst++ = val1 - val2;
        } else {
            *dst++ = 0;
        }
    }
}
