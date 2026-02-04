#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int w;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_j;
    for (outer_j = 0; outer_j < w; outer_j++) {
        int inner_j = outer_j;
        dst[inner_j] = src[-inner_j];
    }
}
