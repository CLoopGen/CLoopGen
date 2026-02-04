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
int j;
for (i = 0; i < width - 5; i += 6) {
    for (j = 0; j < 6; j += 2) {
        val = src[(j + 0)/2];
        if (j == 0 || j == 4) {
            u[j/2] = val & 1023;
            y[j + 0] = (val >> 10) & 1023;
            v[j/2] = (val >> 20) & 1023;
        }
        if (j == 2) {
            v[j/2] = val & 1023;
            y[j + 1] = (val >> 10) & 1023;
            u[j/2] = (val >> 20) & 1023;
        }
        y[j + 1] = val & 1023;
        u[j/2 + 1] = (val >> 10) & 1023;
        y[j + 2] = (val >> 20) & 1023;
    }
    src += 4;
    y += 6;
    u += 6;
    v += 6;
}
}
