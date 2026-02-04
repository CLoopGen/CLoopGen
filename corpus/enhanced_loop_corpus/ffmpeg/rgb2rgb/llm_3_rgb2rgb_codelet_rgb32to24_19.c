#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int i;
extern int num_pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *d = dst;
    const uint8_t *s = src;
    for (i = 0; i < num_pixels; i++) {
        d[0] = s[2];
        d[1] = s[1];
        d[2] = s[0];
        d += 3;
        s += 4;
    }
}
