#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse down columns first, then move to next column (column-major like)
    for (x = 0; x < 4; x++) {
        uint8_t *col_base = dst + x * 4;
        for (y = 0; y < 4; y++) {
            uint8_t *p = col_base + y * stride;
            uint8_t temp = p[1];
            p[1] = p[0];
            p[0] = temp;
        }
    }
}
