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
    uint8_t temp;
    for (x = 0; x < unaligned_w; x++) {
        temp = *src1++ - *src2++;
        *dst++ = temp;
    }
}
