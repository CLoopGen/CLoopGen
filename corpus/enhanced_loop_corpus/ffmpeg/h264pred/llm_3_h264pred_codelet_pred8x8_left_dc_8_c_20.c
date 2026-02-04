#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with explicit pointer arithmetic
    // Use pointer arithmetic with scaled strides to emphasize strided pattern
    // and unroll the loop manually to highlight memory access distance.
    uint8_t *ptr1 = src - 1;
    uint8_t *ptr2 = src - 1 + 4 * stride;
    dc0 += ptr1[0 * stride]; 
    dc0 += ptr1[1 * stride]; 
    dc0 += ptr1[2 * stride]; 
    dc0 += ptr1[3 * stride];
    dc2 += ptr2[0 * stride]; 
    dc2 += ptr2[1 * stride]; 
    dc2 += ptr2[2 * stride]; 
    dc2 += ptr2[3 * stride];
}
