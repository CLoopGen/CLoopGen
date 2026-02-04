#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int ref;
extern int stride;
extern int x;
extern int y;
extern int acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (transpose the iteration order to access memory sequentially)
    uint8_t *base = src;
    acc = 0; // assuming accumulation starts at 0, reset for correctness
    for (x = 0; x < 16; x++) {
        for (y = 0; y < 16; y++) {
            uint8_t val = base[x + y * stride];
            acc += (val >= ref) ? (val - ref) : (ref - val);
        }
    }
}
