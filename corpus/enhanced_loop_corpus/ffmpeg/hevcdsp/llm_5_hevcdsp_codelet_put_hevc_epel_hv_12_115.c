#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 3; y++) {
    for (x = 0; x < width; x++) {
        int index = x + (y < (height + 3) / 2 ? 0 : 1);
        if (x > 1 && x < width - 2)
            tmp[x] = (filter[0] * src[index - 1] + filter[1] * src[index] + filter[2] * src[index + 1] + filter[3] * src[index + 2]) >> 4;
        else
            tmp[x] = 0;
    }
    src += srcstride;
    tmp += 64;
}
}
