#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    while (1) {
        char c = content[offset];
        if (c == ',' || c == '\x00') break;
        offset++;
    }
    p = content + offset;
}
