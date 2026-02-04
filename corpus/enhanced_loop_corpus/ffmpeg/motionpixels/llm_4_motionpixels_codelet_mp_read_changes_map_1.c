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
    for (i = 0; i < w; ++i) {
        if (color >= 0) {
            pixels[i] = color;
        }
    }
}
