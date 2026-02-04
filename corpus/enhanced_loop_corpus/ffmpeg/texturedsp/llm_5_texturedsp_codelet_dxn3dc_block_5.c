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
for (y = 0; y < 4; ++y) {
    for (x = 0; x < 4; ++x) {
        uint8_t *p = dst + x * 4 + y * stride;
        if (p[0] > p[1]) {
            uint8_t temp = p[1];
            p[1] = p[0];
            p[0] = temp;
        } else if (p[1] > p[0]) {
            continue;
        }
    }
}
}
