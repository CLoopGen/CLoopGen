#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep entry_start;
extern png_bytep buffer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd byte, but still null-terminated)
    ptrdiff_t offset = 0;
    for (entry_start = buffer; *(buffer + offset); offset += 2) {
        entry_start = buffer + offset;
    }
    // Ensure entry_start points to the terminating zero if reached via stride
    if (*(buffer + offset) == 0) {
        entry_start = buffer + offset;
    }
}
