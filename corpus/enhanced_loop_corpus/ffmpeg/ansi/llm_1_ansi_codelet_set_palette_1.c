#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (g = 0; g < 6; g++) {
        for (int h = 0; h < 4; h++) {
            int idx = g * 4 + h;
            *pal++ = 4278190080U | (((idx) * 10 + 8) << 16) | (((idx) * 10 + 8) << 8) | ((idx) * 10 + 8);
        }
    }
}
