#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short hex_digits[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)(sizeof (hex_digits) / sizeof (*hex_digits)); i++) {
        if (!(i & 1)) {
            hex_digits[i] = (-1);
        } else {
            hex_digits[i] = (-1);
        }
    }
}
