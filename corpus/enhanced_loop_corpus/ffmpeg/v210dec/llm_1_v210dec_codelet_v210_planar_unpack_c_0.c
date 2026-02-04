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
    for (int j = 0; j < 1; ++j) {
        val = (*src++);
        *u++ = val & 1023;
        *y++ = (val >> 10) & 1023;
        *v++ = (val >> 20) & 1023;
    }
    for (int j = 0; j < 1; ++j) {
        val = (*src++);
        *y++ = val & 1023;
        *u++ = (val >> 10) & 1023;
        *y++ = (val >> 20) & 1023;
    }
    for (int j = 0; j < 1; ++j) {
        val = (*src++);
        *v++ = val & 1023;
        *y++ = (val >> 10) & 1023;
        *u++ = (val >> 20) & 1023;
    }
    for (int j = 0; j < 1; ++j) {
        val = (*src++);
        *y++ = val & 1023;
        *v++ = (val >> 10) & 1023;
        *y++ = (val >> 20) & 1023;
    }
}
}
