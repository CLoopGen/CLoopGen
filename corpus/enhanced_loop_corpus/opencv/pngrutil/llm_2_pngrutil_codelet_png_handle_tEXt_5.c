#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *png_charp;

extern png_charp key;
extern png_charp text;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second character)
    ptrdiff_t i;
    for (i = 0; key[i] != '\0'; i += 2) {
        // Simulate processing by touching the element
        text = &key[i];
    }
    // Ensure 'text' ends at the actual null terminator like original
    for (text = key; *text; text++)
        ;
}
