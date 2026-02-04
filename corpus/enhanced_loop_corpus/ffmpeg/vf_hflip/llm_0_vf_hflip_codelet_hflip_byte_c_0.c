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
    int i, j;
    for (i = 0; i < 1; i++) {
        for (j = 0; j < w; j++) {
            dst[j] = src[-j];
        }
    }
}
