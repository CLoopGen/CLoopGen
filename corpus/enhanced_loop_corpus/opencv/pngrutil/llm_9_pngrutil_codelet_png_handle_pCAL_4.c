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
    size_t i;
    size_t count = 0;
    for (i = 0; i < 1000; i++) {
        buf = units;
        while (*buf) {
            count += *buf;
            buf++;
        }
    }
    (void)count;
}
