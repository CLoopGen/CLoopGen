#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short hex_digits[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < (ssize_t)(sizeof (hex_digits) / sizeof (*hex_digits)); i += 2)
        hex_digits[i] = (-1);
    for (i = 1; i < (ssize_t)(sizeof (hex_digits) / sizeof (*hex_digits)); i += 2)
        hex_digits[i] = (-1);
}
