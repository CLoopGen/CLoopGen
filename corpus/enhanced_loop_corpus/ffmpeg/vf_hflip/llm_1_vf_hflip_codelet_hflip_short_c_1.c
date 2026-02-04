#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint16_t *src;
extern uint16_t *dst;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w > 0) {
        j = 0;
        for (int outer = 0; outer < 1; outer++) {
            for (; j < w; j++) {
                dst[j] = src[-j];
            }
        }
    }
}
