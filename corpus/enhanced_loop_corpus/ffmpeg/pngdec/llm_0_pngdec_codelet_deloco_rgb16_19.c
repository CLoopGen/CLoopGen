#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int size;
extern int alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < size - 2; j += 3 + alpha) {
        for (i = j; i < j + 3 && i < size - 2; ++i) {
            int g = dst[i + 1];
            dst[i + 0] += g;
            dst[i + 2] += g;
        }
    }
}
