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
    int valid_row = (y % 2 == 0); // Process only even-indexed rows
    for (x = 0; x < width; x++) {
        int weighted_sum = filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + 
                           filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2] + 
                           filter[6] * src[x + 3] + filter[7] * src[x + 4];
        if (valid_row) {
            tmp[x] = weighted_sum >> 4;
        } else {
            tmp[x] = 0; // Set to zero for odd rows
        }
    }
    src += srcstride;
    tmp += 64;
}
}
