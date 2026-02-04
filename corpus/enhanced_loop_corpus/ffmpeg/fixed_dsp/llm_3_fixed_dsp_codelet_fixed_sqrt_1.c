#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int bits;
extern int retval;
extern int bit_mask;
extern int guess;
extern int square;
extern int i;
extern int64_t accu;
extern int shift2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with artificial padding to enforce non-unit stride
    // Embed variables in a struct to control layout and access with fixed stride
    struct {
        int pad0;
        int v_retval;
        int pad1[2];
        int v_bit_mask;
        int pad2[3];
        int v_x;
        int pad3[1];
        int v_bits;
    } __attribute__((packed)) regrouped;

    // Initialize the struct with current values
    regrouped.v_retval = retval;
    regrouped.v_bit_mask = bit_mask;
    regrouped.v_x = x;
    regrouped.v_bits = bits;

    // Strided access: step through logical fields with non-consecutive offsets
    for (i = 0; i < shift2; i++) {
        int stride_guess = regrouped.v_retval + regrouped.v_bit_mask;
        accu = (int64_t)stride_guess * stride_guess;
        int stride_square = (int)((accu + regrouped.v_bit_mask) >> regrouped.v_bits);
        if (regrouped.v_x >= stride_square)
            regrouped.v_retval += regrouped.v_bit_mask;
        regrouped.v_bit_mask >>= 1;
    }

    // Update original variables from struct
    retval = regrouped.v_retval;
    bit_mask = regrouped.v_bit_mask;
    x = regrouped.v_x;
    bits = regrouped.v_bits;
}
