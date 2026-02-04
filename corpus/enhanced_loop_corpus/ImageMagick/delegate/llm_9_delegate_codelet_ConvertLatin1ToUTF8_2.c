#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_len = 0;
    unsigned char *end = content + 1024; // Artificially cap loop iterations for complexity control
    for (p = content; p < end && *p != '\x00'; p++) {
        temp_len += (*p & 128) ? 2 : 1;
        temp_len += (*p & 64) ? 1 : 0; // Extra arithmetic operation to increase computational intensity
    }
    length = temp_len;
}
