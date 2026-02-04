#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t acc_left, acc_top;
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            acc_left = left[0]; 
            acc_top = top[0];
            if (x == y)
                d[y * stride + x] = (left[1] + 2 * acc_top + top[1] + 2) >> 2;
            else if (x > y) {
                acc_top = (acc_top + top[(x - y) - 1] + top[(x - y) + 1]) >> 1;
                d[y * stride + x] = ((top[(x - y) - 1] + 2 * top[(x - y)] + top[(x - y) + 1] + 2) >> 2);
            } else {
                acc_left = (acc_left + left[(y - x) - 1] + left[(y - x) + 1]) >> 1;
                d[y * stride + x] = ((left[(y - x) - 1] + 2 * left[(y - x)] + left[(y - x) + 1] + 2) >> 2);
            }
        }
    }
}
