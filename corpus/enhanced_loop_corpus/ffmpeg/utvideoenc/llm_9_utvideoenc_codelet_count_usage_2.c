#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int width;
extern int height;
extern uint64_t *counts;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < height; j += 2) {
    for (i = 0; i < width; i++) {
        counts[src[i]]++;
        if (j + 1 < height) {
            counts[src[i + width]]++;
        }
    }
    src += (j + 1 < height) ? 2 * width : width;
}
}
