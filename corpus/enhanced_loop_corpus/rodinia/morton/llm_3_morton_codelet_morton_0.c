#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *x;
extern int *y;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using a temporary buffer and sequential writes
    int temp_x[16] = {0};
    int temp_y[16] = {0};
    for (b = 0; b < 16; b++) {
        temp_x[b] |= (i & (1 << (b * 2))) >> b;
        temp_y[b] |= (i & (1 << (b * 2 + 1))) >> (b + 1);
    }
    // Flush results to output pointers consecutively
    for (b = 0; b < 16; b++) {
        x[b] = temp_x[b];
        y[b] = temp_y[b];
    }
}
