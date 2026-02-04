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
for (i = 0; i < width - 11; i += 12) {
    val = src[0];
    u[0] = val & 1023;
    y[0] = (val >> 10) & 1023;
    v[0] = (val >> 20) & 1023;
    
    val = src[1];
    y[1] = val & 1023;
    u[1] = (val >> 10) & 1023;
    y[2] = (val >> 20) & 1023;
    
    val = src[2];
    v[1] = val & 1023;
    y[3] = (val >> 10) & 1023;
    u[2] = (val >> 20) & 1023;
    
    val = src[3];
    y[4] = val & 1023;
    v[2] = (val >> 10) & 1023;
    y[5] = (val >> 20) & 1023;

    val = src[4];
    u[3] = val & 1023;
    y[6] = (val >> 10) & 1023;
    v[3] = (val >> 20) & 1023;
    
    val = src[5];
    y[7] = val & 1023;
    u[4] = (val >> 10) & 1023;
    y[8] = (val >> 20) & 1023;
    
    val = src[6];
    v[4] = val & 1023;
    y[9] = (val >> 10) & 1023;
    u[5] = (val >> 20) & 1023;
    
    val = src[7];
    y[10] = val & 1023;
    v[5] = (val >> 10) & 1023;
    y[11] = (val >> 20) & 1023;

    src += 8;
    y += 12;
    u += 6;
    v += 6;
}
}
