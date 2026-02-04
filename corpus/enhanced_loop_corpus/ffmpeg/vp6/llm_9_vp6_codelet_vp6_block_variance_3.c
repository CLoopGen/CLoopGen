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
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        int val1 = src[x];
        int val2 = src[x + 1];
        sum += val1 + val2;
        square_sum += val1 * val1 + val2 * val2;
    }
    for (x = 0; x < 4; x++) {
        int val1 = src[stride + x];
        int val2 = src[stride + x + 1];
        sum += val1 + val2;
        square_sum += val1 * val1 + val2 * val2;
    }
    src += 2 * stride;
}
}
