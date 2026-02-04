#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x -= 7; x >= 0; x -= 8) {
        for (int offset = 0; offset < 8; offset += 2) {
            dst[x + offset] = dst[x + offset + 1] = src[(x >> 1) + (offset >> 1)];
        }
    }
}
