#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y_inner;
    for (y = 0; y < height; y++) {
        for (y_inner = 0; y_inner < 1; y_inner++) {
            dst += stride;
            src += stride;
        }
    }
}
