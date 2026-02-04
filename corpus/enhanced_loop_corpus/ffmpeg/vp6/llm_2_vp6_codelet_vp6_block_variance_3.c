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
    // Variant 1: Consecutive memory access with unrolled accumulation
    uint8_t *row = src;
    for (y = 0; y < 8; y += 2) {
        sum += row[0] + row[2];
        sum += row[4] + row[6];
        square_sum += row[0] * row[0] + row[2] * row[2];
        square_sum += row[4] * row[4] + row[6] * row[6];
        row += 2 * stride;
    }
}
