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
    uint16_t *p = pixels;
    int temp_color = color;
    for (i = 0; i < w; ++i) {
        p[i] = temp_color;
        temp_color = p[i]; // Introduce artificial RAW and WAW dependency: reuse written value
    }
}
