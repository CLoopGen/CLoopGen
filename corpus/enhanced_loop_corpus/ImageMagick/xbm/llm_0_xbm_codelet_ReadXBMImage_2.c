#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short hex_digits[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < 1; outer++) {
        for (i = 0; i < (ssize_t)(sizeof (hex_digits) / sizeof (*hex_digits)); i++)
            hex_digits[i] = (-1);
    }
}
