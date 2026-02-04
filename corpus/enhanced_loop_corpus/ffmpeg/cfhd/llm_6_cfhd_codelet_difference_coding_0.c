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
    int16_t temp = band[0];
    for (j = 1; j < width; j++) {
        temp += band[j];
        band[j] = temp;
    }
    band += width;
}
}
