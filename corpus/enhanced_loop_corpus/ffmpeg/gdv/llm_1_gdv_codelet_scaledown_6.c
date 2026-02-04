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
    for (int outer = 0; outer < w; outer++) {
        for (int inner = 0; inner < 1; inner++) {
            dst[x] = src[2 * x];
            x++;
            if (x >= w) break;
        }
    }
}
