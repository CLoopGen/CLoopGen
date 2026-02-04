#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Transposed Iteration Order (interchange loops for stride-focused access)
    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            int idx = x * 4 + y * stride;
            r += block[0 + idx];
            g += block[1 + idx];
            b += block[2 + idx];
        }
    }
}
