#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t **indices = (uint8_t**)malloc(height * sizeof(uint8_t*));
    for (i = 0; i < height; i++) {
        indices[i] = dst + i * stride_dst;
    }
    for (i = 0; i < height; i++) {
        *(uint16_t *)indices[i] = *(uint16_t *)(src + i * stride_src);
    }
    free(indices);
}
