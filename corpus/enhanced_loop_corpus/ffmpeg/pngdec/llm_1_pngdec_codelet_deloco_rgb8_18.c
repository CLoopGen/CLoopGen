#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int size;
extern int alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size - 2; i += 3 + alpha) {
        if (i + 1 < size) {
            int g = dst[i + 1];
            dst[i + 0] += g;
            if (i + 2 < size) {
                dst[i + 2] += g;
            }
        }
    }
}
