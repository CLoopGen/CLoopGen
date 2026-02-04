#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t weight[10];
extern int16_t max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    for (i = 0; i < 10; i++) {
        int index = (i * 2) % 10;  // Access elements with stride 2: 0, 2, 4, ..., 8, 0, 2, ...
        max = (weight[index] > max) ? weight[index] : max;
    }
}
