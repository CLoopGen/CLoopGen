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
    for (int j = 0; j < 2; ++j) {
        for (i = 0; i < size - 2; i += 3 + alpha) {
            int g = dst[i + 1];
            dst[i + 0] += g;
            dst[i + 2] += g;
        }
    }
}
