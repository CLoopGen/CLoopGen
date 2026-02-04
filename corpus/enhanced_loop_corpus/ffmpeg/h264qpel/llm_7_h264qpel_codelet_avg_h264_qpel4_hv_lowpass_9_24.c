#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h + 5; i++) {
        uint16_t *s = src;
        int16_t *t = tmp;
        t[0] = (s[0] + s[1]) * 20 - (s[-1] + s[2]) * 5 + (s[-2] + s[3]) + pad;
        t[1] = (s[1] + s[2]) * 20 - (s[0] + s[3]) * 5 + (s[-1] + s[4]) + pad;
        t[2] = (s[2] + s[3]) * 20 - (s[1] + s[4]) * 5 + (s[0] + s[5]) + pad;
        t[3] = (s[3] + s[4]) * 20 - (s[2] + s[5]) * 5 + (s[1] + s[6]) + pad;
        // Introduce artificial loop-carried dependency via pad update
        pad = (pad + t[0] + t[1] + t[2] + t[3]) & 0xFF; // Reduce influence but maintain dependency
        tmp += tmpStride;
        src += srcStride;
    }
}
