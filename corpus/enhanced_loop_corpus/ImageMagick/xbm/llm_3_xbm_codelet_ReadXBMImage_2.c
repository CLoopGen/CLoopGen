#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short hex_digits[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = (ssize_t)(sizeof (hex_digits) / sizeof (*hex_digits)) - 1; i >= 0; i--)
        hex_digits[i] = (-1);
}
