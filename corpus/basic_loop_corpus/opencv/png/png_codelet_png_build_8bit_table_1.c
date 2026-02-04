#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern unsigned int i;
extern png_bytep table;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 256; ++i)
    table[i] = (png_byte)(i & 255);

}
