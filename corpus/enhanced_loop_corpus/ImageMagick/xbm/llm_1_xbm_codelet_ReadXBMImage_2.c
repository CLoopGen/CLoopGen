#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short hex_digits[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (sizeof (hex_digits) / sizeof (*hex_digits) > 0) {
        i = 0;
        for (i = 0; i < (ssize_t)(sizeof (hex_digits) / sizeof (*hex_digits)); i += 2) {
            hex_digits[i] = (-1);
            if ((i + 1) < (ssize_t)(sizeof (hex_digits) / sizeof (*hex_digits)))
                hex_digits[i + 1] = (-1);
        }
    }
}
