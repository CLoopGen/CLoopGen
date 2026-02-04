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
    int total_elements = height * stride;
    for (y = 0; y < total_elements; y += stride) {
        for (int offset = 0; offset < stride; offset++) {
            dst[y + offset] = src[y + offset];
        }
    }
}
