#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *ptr;
extern int sum;
extern int i;
extern int min_pix;
extern int max_pix;
extern uint8_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // To maintain 8 effective iterations, we double the upper bound and step by 2
    for (i = 0; i < 16; i += 2) {
        c = *(ptr + i);
        sum += c;
        min_pix = ((min_pix) > (c) ? (c) : (min_pix));
        max_pix = ((max_pix) > (c) ? (max_pix) : (c));
    }
}
