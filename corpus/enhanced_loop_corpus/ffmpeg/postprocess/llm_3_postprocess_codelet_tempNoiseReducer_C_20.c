#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *tempBlurred;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed loop order (column-major traversal) to increase stride in outer dimension
    for (int x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            int addr = x + y * stride;
            int ref = tempBlurred[addr];
            int cur = src[addr];
            tempBlurred[addr] = src[addr] = (ref + cur + 1) >> 1;
        }
    }
}
