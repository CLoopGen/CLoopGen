#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *pixels;
extern int w;
extern int color;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_color = color ^ 0xFFFF;
    for (i = 0; i < w * 2; i += 2) {
        pixels[i / 2] = local_color;
    }
}
