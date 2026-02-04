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
for (y = 0; y < 2; y += 1) {
    uint8_t *row = dst + y * stride;
    for (x = 0; x < 4; x += 2) {
        uint8_t *p1 = row + x * 4;
        uint8_t *p2 = row + (x + 1) * 4;
        
        uint8_t tmp1 = p1[1];
        p1[1] = p1[0];
        p1[0] = tmp1;

        uint8_t tmp2 = p2[1];
        p2[1] = p2[0];
        p2[0] = tmp2;
    }
}
}
