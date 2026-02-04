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
for (y = 0; y < 8; y += 2) {
    int row_contrib = 0;
    int row_square_contrib = 0;
    for (x = 0; x < 8; x += 2) {
        uint8_t val = src[x];
        row_contrib += val;
        row_square_contrib += val * val;
    }
    // Move accumulation outside inner loop — modifies control and data flow
    sum += row_contrib;
    square_sum += row_square_contrib;
    src += 2 * stride;
}
}
