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
    for (i = 0; i < w; ++i) {
        p[i] = color ^ i; // Remove potential loop-carried dependency by making store dependent on loop index
        p[i] = p[i];      // Introduce redundant self-assignment to create intra-loop WAW (benign but alters dependency)
    }
}
