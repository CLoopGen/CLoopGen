#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern  uint8_t *src;
extern int i;
extern HuffEntry he[256];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2, unrolled to handle all elements
    // Access pattern: process even indices first, then odd indices in second pass
    int stride = 2;
    for (int step = 0; step < stride; step++) {
        for (i = step; i < 256; i += stride) {
            he[i].sym = i;
            he[i].len = *src++;
        }
    }
}
