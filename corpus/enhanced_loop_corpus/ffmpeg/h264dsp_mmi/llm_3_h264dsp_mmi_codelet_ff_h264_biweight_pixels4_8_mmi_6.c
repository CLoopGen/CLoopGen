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
    uint8_t **indices = (uint8_t**)malloc(height * sizeof(uint8_t*));
    for (y = 0; y < height; y++) {
        indices[y] = &src[y * stride];
    }
    for (y = 0; y < height; y++, dst += stride) {
        *dst = *(indices[y]);
    }
    free(indices);
}
