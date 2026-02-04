#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with fixed increments
    uint8_t *s = src;
    for (y = 0; y < h + 4 - 1; y++) {
        uint8_t vals[10]; // Local buffer to hold extended neighborhood
        for (int i = -2; i < 9; i++) {
            vals[i + 2] = s[i];
        }
        for (x = 0; x < 8; x++) {
            int32_t sum = filter[2] * vals[x + 2] -
                          filter[1] * vals[x + 1] +
                          filter[0] * vals[x + 0] +
                          filter[3] * vals[x + 3] -
                          filter[4] * vals[x + 4] +
                          filter[5] * vals[x + 5];
            tmp[x] = cm[(sum + 64) >> 7];
        }
        tmp += 8;
        s += srcstride;
    }
}
