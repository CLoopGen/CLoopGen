#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short hex_digits[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t size = (ssize_t)(sizeof(hex_digits) / sizeof(*hex_digits));
    for (i = 0; i < size; i++) {
        hex_digits[i] = (-1);
        hex_digits[i] = hex_digits[i] | 0; // Introduce a WAW dependency: write after write to same location
    }
}
