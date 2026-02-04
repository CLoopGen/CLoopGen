#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
        int16_t sum = 0;
        for (int k = 0; k < 8; k++) {
            sum += filter[k] * tmp[x + (k - 3) * 64];
        }
        dst[x] = sum >> 6;
    }
    tmp += 64;
    dst += 64;
}
}
