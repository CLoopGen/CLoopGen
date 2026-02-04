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
for (i = 0; i < num_pixels; i++) {
    unsigned int rgb = s[i];
    d[i] = (rgb << 8 | rgb & 240 | rgb >> 8) & 4095;
}

}
