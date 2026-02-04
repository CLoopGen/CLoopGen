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
    png_bytep temp = buffer;
    for (; temp && *temp; temp++) {
        if (*(temp + 1) == 0) {
            entry_start = temp + 1;
            break;
        }
    }
    entry_start = temp;
}
