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
uint32_t local_val;
for (i = 0; i < width - 5; i += 6) {
    local_val = src[0];
    *u++ = local_val & 1023;
    *y++ = (local_val >> 10) & 1023;
    *v++ = (local_val >> 20) & 1023;

    local_val = src[1];
    *y++ = local_val & 1023;
    *u++ = (local_val >> 10) & 1023;
    *y++ = (local_val >> 20) & 1023;

    local_val = src[2];
    *v++ = local_val & 1023;
    *y++ = (local_val >> 10) & 1023;
    *u++ = (local_val >> 20) & 1023;

    local_val = src[3];
    *y++ = local_val & 1023;
    *v++ = (local_val >> 10) & 1023;
    *y++ = (local_val >> 20) & 1023;

    src += 4;
}
}
