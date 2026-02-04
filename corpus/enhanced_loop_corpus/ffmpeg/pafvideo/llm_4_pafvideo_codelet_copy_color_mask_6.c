#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern uint8_t color;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int shift1 = 7 - i;
    int shift2 = 3 - i;
    uint8_t cond1 = mask & (1 << shift1);
    uint8_t cond2 = mask & (1 << shift2);

    if (cond1) {
        dst[i] = color;
        if (cond2) {
            dst[width + i] = color;
        }
    } else if (cond2) {
        dst[width + i] = color;
    }
}
}
