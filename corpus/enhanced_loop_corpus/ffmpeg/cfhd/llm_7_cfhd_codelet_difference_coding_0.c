#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *band;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    int16_t prev = band[0];
    for (j = 1; j < width; j++) {
        int16_t current = band[j];
        band[j] = prev;
        prev = current;
    }
    band += width;
}
}
