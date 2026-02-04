#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint32_t *src;
extern uint32_t *dst;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w > 0) {
        j = 0;
        for (; j < w; j++) {
            dst[j] = src[-j];
        }
    }
}
