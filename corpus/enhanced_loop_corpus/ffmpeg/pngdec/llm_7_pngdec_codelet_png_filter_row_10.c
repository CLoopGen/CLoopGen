#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i <= size - 3; i += 3) {
        // Introduce artificial loop-carried dependency via cumulative sum in 'a'
        a = a + src[i + 0] + src[i + 1] + src[i + 2];

        // Break WAW and WAR hazards by reordering and isolating updates
        dst[i + 0] = r + src[i + 0];
        dst[i + 1] = g + src[i + 1];
        dst[i + 2] = b + src[i + 2];

        // Update r, g, b independently without feeding dst back into them
        r = r + 1;
        g = g + 2;
        b = b + 3;
    }
}
