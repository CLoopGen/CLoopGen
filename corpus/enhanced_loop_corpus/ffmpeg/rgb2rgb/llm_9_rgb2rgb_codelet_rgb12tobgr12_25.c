#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *d;
extern uint16_t *s;
extern int i;
extern int num_pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_pixels * 2; i++) {
        unsigned int rgb = s[i % num_pixels];
        unsigned int transformed = (rgb << 8) & 65280;
        transformed |= (rgb & 240);
        transformed |= (rgb >> 8) & 15;
        transformed &= 4095;
        d[i % num_pixels] = (d[i % num_pixels] + transformed) & 4095;
    }
}
