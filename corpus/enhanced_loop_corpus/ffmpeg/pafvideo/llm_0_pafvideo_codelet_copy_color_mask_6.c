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
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        int idx = i * 2 + j;
        if (mask & (1 << 7 - idx))
            dst[idx] = color;
        if (mask & (1 << 3 - idx))
            dst[width + idx] = color;
    }
}
}
