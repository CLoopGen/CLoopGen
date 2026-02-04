#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    length = 0;
    for (p = content; *p != '\x00'; p += (*p & 128) ? 2 : 1)
        length += (*p & 64) ? 3 : 1;
}
