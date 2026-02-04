#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int sum;
extern int square_sum;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    int temp_square_sum = 0;
    for (y = 0; y < 8; y += 2) {
        for (x = 0; x < 8; x += 2) {
            int val = src[x];
            temp_sum += val;
            temp_square_sum += val * val;
        }
        src += 2 * stride;
    }
    sum += temp_sum;
    square_sum += temp_square_sum;
}
