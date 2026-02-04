#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int num_pixels;
extern  uint8_t *palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(num_pixels * sizeof(int));
    for (int j = 0; j < num_pixels; j++) {
        indices[j] = j;
    }
    for (int j = 0; j < num_pixels; j++) {
        int idx = indices[j];
        ((uint32_t *)dst)[idx] = ((const uint32_t *)palette)[src[idx]];
    }
    free(indices);
}
