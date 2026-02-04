#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < 1; j++) { // Artificially nested with depth 2
            dst[i] = src[(i >> 1)];
        }
    }
}
