#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short hex_digits[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled-like pattern
    ssize_t size = (ssize_t)(sizeof(hex_digits) / sizeof(*hex_digits));
    for (i = 0; i < size; i += 4) {
        hex_digits[i] = (-1) * (1 + (i % 2)); // Extra arithmetic: introduce multiplication and modulo
        if (i + 1 < size) hex_digits[i + 1] = (-1) * (1 + ((i+1) % 2));
        if (i + 2 < size) hex_digits[i + 2] = (-1) * (1 + ((i+2) % 2));
        if (i + 3 < size) hex_digits[i + 3] = (-1) * (1 + ((i+3) % 2));
    }
}
