#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height + 1; y++) {
        for (x = 0; x < width; x++) {
            int16_t sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += filter[k] * src[x + k - 1];
            }
            tmp[x] = sum >> 8;
        }
        src += srcstride;
        tmp += 64;
    }
}
