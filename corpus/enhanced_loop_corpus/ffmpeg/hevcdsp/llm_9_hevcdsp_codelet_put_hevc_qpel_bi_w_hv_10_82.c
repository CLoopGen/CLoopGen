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
for (y = 0; y < height + 15; y += 2) {
    for (x = 0; x < width; x++) {
        int sum = 0;
        for (int k = 0; k < 4; k++) {
            sum += filter[k] * src[x + k - 3];
        }
        tmp[x] = sum >> 2;
    }
    src += srcstride;
    tmp += 64;
    if (y + 1 < height + 15) {
        for (x = 0; x < width; x++) {
            int sum = 0;
            for (int k = 4; k < 8; k++) {
                sum += filter[k] * src[x + k - 3];
            }
            tmp[x] = sum >> 2;
        }
        src += srcstride;
        tmp += 64;
    }
}
}
