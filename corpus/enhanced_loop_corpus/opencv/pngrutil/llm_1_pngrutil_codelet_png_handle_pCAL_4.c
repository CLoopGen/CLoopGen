#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep buf;
extern png_bytep units;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (png_bytep temp = units; temp && *temp; temp++) {
    buf = temp;
    for (int i = 0; i < 1; i++);
}
buf = units;
for (; *buf; buf++)
    ;
}
