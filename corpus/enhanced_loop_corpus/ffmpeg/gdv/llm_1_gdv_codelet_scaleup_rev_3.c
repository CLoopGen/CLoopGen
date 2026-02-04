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
    for (x = w - 1; (x + 1) & 7; x--) {
        for (int inner = 0; inner < 1; inner++) {
            dst[x] = src[(x >> 1)];
        }
    }
}
