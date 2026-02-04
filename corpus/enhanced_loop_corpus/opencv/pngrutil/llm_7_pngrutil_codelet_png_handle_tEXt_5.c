#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef char *png_charp;

extern png_charp key;
extern png_charp text;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t offset = 0;
    for (; key[offset]; offset++) {
        text = key + offset;
    }
}
