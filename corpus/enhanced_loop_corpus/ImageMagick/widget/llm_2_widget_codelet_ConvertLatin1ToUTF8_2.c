#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd element, then handle odd positions)
    size_t i;
    for (i = 0; content + i < p + 256 && content + i < content + length; i += 2) {
        unsigned char c1 = content[i];
        if (c1 == '\x00') break;
        length += (c1 & 128) ? 2 : 1;
        if (content[i+1] == '\x00') break;
        length += (content[i+1] & 128) ? 2 : 1;
    }
    // Resume from where the original p might be, assuming bounds are managed externally
}
