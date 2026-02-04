#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < 4; i++) {
            if (mask & (1 << 7 - i))
                dst[i] = src[i];
            if (j == 1 && (mask & (1 << 3 - i)))
                dst[width + i] = src[width + i];
        }
    }
}
