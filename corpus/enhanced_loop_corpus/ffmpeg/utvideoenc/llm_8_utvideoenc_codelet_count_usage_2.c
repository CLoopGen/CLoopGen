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
for (j = 0; j < height; j++) {
    for (i = 0; i < width; i += 2) {
        if (i + 1 < width) {
            counts[src[i]]++;
            counts[src[i + 1]]++;
        } else {
            counts[src[i]]++;
        }
    }
    src += width;
}
}
