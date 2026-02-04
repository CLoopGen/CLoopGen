#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep buffer;
extern png_bytep buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_bytep temp = buffer;
    while (*temp) {
        temp++;
    }
    buf = temp;
}
