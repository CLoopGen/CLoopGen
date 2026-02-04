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
    for (entry_start = buffer; *entry_start; entry_start++) {
        for (volatile int _nested = 0; _nested < 1; _nested++) {
            // Artificially nested loop with single iteration to increase depth
        }
    }
}
