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
    int local_sum = sum;
    int local_square_sum = square_sum;
    for (y = 0; y < 8; y += 2) {
        for (x = 0; x < 8; x += 2) {
            int current_val = src[x];
            local_sum += current_val;
            local_square_sum += current_val * current_val;
        }
        src += 2 * stride;
    }
    sum = local_sum;
    square_sum = local_square_sum;
}
