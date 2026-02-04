#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t prev_char = 0;
    for (p = content; *p != '\x00'; p++) {
        length += ((*p & 128) != 0) + ((*p & 128) != 0 || (prev_char & 64));
        prev_char = *p;
    }
}
