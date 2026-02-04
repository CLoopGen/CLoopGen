#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x++) {
        int16_t sum = 0;
        const int offsets[] = {-3, -2, -1, 0, 1, 2, 3, 4};
        for (int k = 0; k < 8; k++) {
            sum += filter[k] * src[x + offsets[k]];
        }
        tmp[x] = sum >> 1;
    }
    src += srcstride;
    tmp += 64;
}
}
