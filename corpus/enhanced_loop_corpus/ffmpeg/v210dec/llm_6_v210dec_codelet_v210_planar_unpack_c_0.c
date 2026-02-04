#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t *src;
extern uint16_t *y;
extern uint16_t *u;
extern uint16_t *v;
extern int width;
extern uint32_t val;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width - 5; i += 6) {
    uint32_t temp1 = src[0];
    uint32_t temp2 = src[1];
    uint32_t temp3 = src[2];
    uint32_t temp4 = src[3];

    *u++ = temp1 & 1023;
    *y++ = (temp1 >> 10) & 1023;
    *v++ = (temp1 >> 20) & 1023;

    *y++ = temp2 & 1023;
    *u++ = (temp2 >> 10) & 1023;
    *y++ = (temp2 >> 20) & 1023;

    *v++ = temp3 & 1023;
    *y++ = (temp3 >> 10) & 1023;
    *u++ = (temp3 >> 20) & 1023;

    *y++ = temp4 & 1023;
    *v++ = (temp4 >> 10) & 1023;
    *y++ = (temp4 >> 20) & 1023;

    src += 4;
}
}
