#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; content[i] != '\x00'; i++) {
        length += (content[i] & 128) != 0 ? 2 : 1;
    }
    p = content + i;
}
