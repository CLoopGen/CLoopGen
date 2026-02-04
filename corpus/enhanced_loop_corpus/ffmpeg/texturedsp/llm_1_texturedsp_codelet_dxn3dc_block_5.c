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
    for (int idx = 0; idx < 16; idx++) {
        int y = idx >> 2;  // Equivalent to idx / 4
        int x = idx & 3;   // Equivalent to idx % 4
        uint8_t *p = dst + x * 4 + y * stride;
        uint8_t temp = p[1];
        p[1] = p[0];
        p[0] = temp;
    }
}
