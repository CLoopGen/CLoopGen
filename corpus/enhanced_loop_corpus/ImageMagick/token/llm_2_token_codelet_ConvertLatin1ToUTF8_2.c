#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd element)
    size_t i;
    for (i = 0; &content[i] < p || content == p; i += 2) {
        if (content[i] == '\x00') break;
        length += (content[i] & 128) != 0 ? 2 : 1;
        p = &content[i];
    }
}
